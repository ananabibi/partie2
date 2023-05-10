#include "Config.hpp"
#include <JSON/JSONSerialiser.hpp>
// window


Config::Config (const j::Value& cfg): mConfig(cfg)
, simulation_debug(mConfig["debug"].toBool())
, window_simulation_width(mConfig["window"]["simulation"]["size"].toDouble())
, window_simulation_height(mConfig["window"]["simulation"]["size"].toDouble())
, window_stats_height(mConfig["window"]["stats"]["height"].toDouble())
 , window_control_width(mConfig["window"]["control"]["width"].toDouble())
, window_title(mConfig["window"]["title"].toString())
, window_antialiasing_level(mConfig["window"]["antialiasing level"].toInt())
 
// stats
, stats_refresh_rate(mConfig["stats"]["refresh rate"].toDouble())

// simulation

, simulation_time_factor(mConfig["simulation"]["time"]["factor"].toDouble())
, simulation_fixed_step(mConfig["simulation"]["time"]["fixed step"].toDouble())
, simulation_time_max_dt(sf::seconds(mConfig["simulation"]["time"]["max dt"].toDouble()))
   , simulation_world_texture(mConfig["simulation"]["world"]["texture"].toString())
   , simulation_world_debug_texture(mConfig["simulation"]["world"]["debug texture"].toString())
				   //, simulation_size(mConfig["simulation"]["world"]["default size"].toInt())								   
   // world
,world_size(mConfig["simulation"]["world"]["default size"].toDouble())
,environment_breeding_delay(mConfig["simulation"]["world"]["breeding delay"].toDouble())
,environment_default_temperature(mConfig["simulation"]["world"]["temperature"]["default"].toDouble())
 ,environment_min_temperature(mConfig["simulation"]["world"]["temperature"]["min"].toDouble())
 ,environment_max_temperature(mConfig["simulation"]["world"]["temperature"]["max"].toDouble())
  // living entity
,entity_texture_tracked(mConfig["simulation"]["living entity"]["tracked texture"].toString())
,entity_energy_critical(mConfig["simulation"]["living entity"]["critical energy"].toDouble())
,entity_repulsive_force(mConfig["simulation"]["living entity"]["repulsive force"].toDouble())
 // bush
, bush_texture(mConfig["simulation"]["bush"]["texture"].toString())
, bush_initial_energy(mConfig["simulation"]["bush"]["energy"]["initial"].toDouble())
, bush_max_energy(mConfig["simulation"]["bush"]["energy"]["max"].toDouble())
, bush_min_energy(mConfig["simulation"]["bush"]["energy"]["min"].toDouble())
, bush_growth_factor(mConfig["simulation"]["bush"]["energy"]["growth factor"].toDouble())
, bush_max_spread_count(mConfig["simulation"]["bush"]["spread"]["max count"].toInt())
, bush_energy_ratio_to_spread(mConfig["simulation"]["bush"]["spread"]["min energy ratio"].toInt())
, bush_distance_to_water(mConfig["simulation"]["bush"]["spread"]["distance to water"].toInt())
,bush_spread_proba(mConfig["simulation"]["bush"]["spread"]["probability"].toDouble())
  // water
  , water_texture(mConfig["simulation"]["water"]["texture"].toString())
   , water_size(mConfig["simulation"]["water"]["size"].toDouble())
  , water_evaporation_threshold(mConfig["simulation"]["water"]["evaporation"]["threshold"].toDouble())
  ,water_evaporation_rate(mConfig["simulation"]["water"]["evaporation"]["rate"].toDouble())

// animal
, animal_random_walk_low_energy(mConfig["simulation"]["animal"]["random walk low energy"].toBool())
 , animal_low_energy_factor(mConfig["simulation"]["animal"]["low energy factor"].toDouble())
//, animal_safe_distance(mConfig["simulation"]["animal"]["random walk low energy"].toDouble())
, animal_meal_retention(mConfig["simulation"]["animal"]["meal retention"].toDouble())
, animal_feed_time(mConfig["simulation"]["animal"]["feed time"].toDouble())
, animal_delivery_time(mConfig["simulation"]["animal"]["reproduction"]["delivery time"].toDouble())
, animal_mating_time(mConfig["simulation"]["animal"]["reproduction"]["mating time"].toDouble())
, animal_satiety_min(mConfig["simulation"]["animal"]["satiety"]["min"].toDouble())
, animal_satiety_max(mConfig["simulation"]["animal"]["satiety"]["max"].toDouble())
, animal_thirst_delay(mConfig["simulation"]["animal"]["thirst delay"].toDouble())
, animal_thirst_max_duration(mConfig["simulation"]["animal"]["thirst max duration"].toDouble())
, animal_idle_probability(mConfig["simulation"]["animal"]["idle"]["probability"].toDouble())
, animal_idle_time_min(mConfig["simulation"]["animal"]["idle"]["min"].toDouble())
, animal_idle_time_max(mConfig["simulation"]["animal"]["idle"]["max"].toDouble())
, animal_base_energy_consumption(mConfig["simulation"]["animal"]["base consumption"].toDouble())
, animal_min_energy(mConfig["simulation"]["animal"]["min energy"].toDouble())
, animal_pregnancy_probability(mConfig["simulation"]["animal"]["reproduction"]["pregnancy proba"].toDouble())
, distance_attraction_to_leader(mConfig["simulation"]["animal"]["distance attraction to leader"].toDouble())
, animal_rotation_delay(mConfig["simulation"]["animal"]["rotation delay"].toDouble())
// buffalo
, buffalo_max_speed(mConfig["simulation"]["animal"]["buffalo"]["max speed"].toDouble())
, buffalo_mass(mConfig["simulation"]["animal"]["buffalo"]["mass"].toDouble())
, buffalo_energy_loss_factor(mConfig["simulation"]["animal"]["buffalo"]["energy"]["loss factor"].toDouble())
, buffalo_view_range(mConfig["simulation"]["animal"]["buffalo"]["view"]["range"].toDouble())
, buffalo_view_distance(mConfig["simulation"]["animal"]["buffalo"]["view"]["distance"].toDouble())
, buffalo_random_walk_jitter(mConfig["simulation"]["animal"]["buffalo"]["random walk"]["jitter"].toDouble())
, buffalo_random_walk_radius(mConfig["simulation"]["animal"]["buffalo"]["random walk"]["radius"].toDouble())
, buffalo_random_walk_distance(mConfig["simulation"]["animal"]["buffalo"]["random walk"]["distance"].toDouble())
, buffalo_longevity(sf::seconds(mConfig["simulation"]["animal"]["buffalo"]["longevity"].toDouble()))
, buffalo_energy_initial(mConfig["simulation"]["animal"]["buffalo"]["energy"]["initial"].toDouble())
, buffalo_energy_min_mating_female(mConfig["simulation"]["animal"]["buffalo"]["energy"]["min mating female"].toDouble())
, buffalo_energy_min_mating_male(mConfig["simulation"]["animal"]["buffalo"]["energy"]["min mating male"].toDouble())
, buffalo_reproduction_min_children(mConfig["simulation"]["animal"]["buffalo"]["reproduction"]["min children"].toInt())
, buffalo_reproduction_max_children(mConfig["simulation"]["animal"]["buffalo"]["reproduction"]["max children"].toInt())
, buffalo_reproduction_gestation_time(mConfig["simulation"]["animal"]["buffalo"]["reproduction"]["gestation time"].toDouble())
, buffalo_energy_loss_female_per_child(mConfig["simulation"]["animal"]["buffalo"]["energy"]["loss female per child"].toDouble())
, buffalo_energy_loss_mating_male(mConfig["simulation"]["animal"]["buffalo"]["energy"]["loss mating male"].toDouble())
//, buffalo_texture_leader(mConfig["simulation"]["animal"]["buffalo"]["texture"]["leader"].toString())
, buffalo_texture_black_male(mConfig["simulation"]["animal"]["buffalo"]["texture"]["black male"].toString())
, buffalo_texture_black_female(mConfig["simulation"]["animal"]["buffalo"]["texture"]["black female"].toString())
, buffalo_texture_gray_male(mConfig["simulation"]["animal"]["buffalo"]["texture"]["gray male"].toString())
, buffalo_texture_gray_female(mConfig["simulation"]["animal"]["buffalo"]["texture"]["gray female"].toString())
, buffalo_size(mConfig["simulation"]["animal"]["buffalo"]["size"].toDouble())
, buffalo_energy_bite(mConfig["simulation"]["animal"]["buffalo"]["energy"]["bite"].toDouble())

// lion
, lion_max_speed(mConfig["simulation"]["animal"]["lion"]["max speed"].toDouble())
, lion_mass(mConfig["simulation"]["animal"]["lion"]["mass"].toDouble())
, lion_energy_loss_factor(mConfig["simulation"]["animal"]["lion"]["energy"]["loss factor"].toDouble())
, lion_view_range(mConfig["simulation"]["animal"]["lion"]["view"]["range"].toDouble())
, lion_view_distance(mConfig["simulation"]["animal"]["lion"]["view"]["distance"].toDouble())
, lion_random_walk_jitter(mConfig["simulation"]["animal"]["lion"]["random walk"]["jitter"].toDouble())
, lion_random_walk_radius(mConfig["simulation"]["animal"]["lion"]["random walk"]["radius"].toDouble())
, lion_random_walk_distance(mConfig["simulation"]["animal"]["lion"]["random walk"]["distance"].toDouble())
, lion_longevity(sf::seconds(mConfig["simulation"]["animal"]["lion"]["longevity"].toDouble()))
, lion_energy_initial(mConfig["simulation"]["animal"]["lion"]["energy"]["initial"].toDouble())
, lion_energy_min_mating_female(mConfig["simulation"]["animal"]["lion"]["energy"]["min mating female"].toDouble())
, lion_energy_min_mating_male(mConfig["simulation"]["animal"]["lion"]["energy"]["min mating male"].toDouble())
, lion_reproduction_min_children(mConfig["simulation"]["animal"]["lion"]["reproduction"]["min children"].toInt())
, lion_reproduction_max_children(mConfig["simulation"]["animal"]["lion"]["reproduction"]["max children"].toInt())
, lion_reproduction_gestation_time(mConfig["simulation"]["animal"]["lion"]["reproduction"]["gestation time"].toDouble())
, lion_energy_loss_female_per_child(mConfig["simulation"]["animal"]["lion"]["energy"]["loss female per child"].toDouble())
, lion_energy_loss_mating_male(mConfig["simulation"]["animal"]["lion"]["energy"]["loss mating male"].toDouble())
//, lion_texture_leader(mConfig["simulation"]["animal"]["lion"]["texture"]["leader"].toString())
, lion_texture_male(mConfig["simulation"]["animal"]["lion"]["texture"]["male"].toString())
, lion_texture_female(mConfig["simulation"]["animal"]["lion"]["texture"]["female"].toString())
, lion_size(mConfig["simulation"]["animal"]["lion"]["size"].toDouble())
, lion_idle_probability(mConfig["simulation"]["animal"]["lion"]["idle"]["probability"].toDouble())
, lion_idle_time_min(mConfig["simulation"]["animal"]["lion"]["idle"]["min"].toDouble())
, lion_idle_time_max(mConfig["simulation"]["animal"]["lion"]["idle"]["max"].toDouble())
, lion_satiety_min(mConfig["simulation"]["animal"]["lion"]["satiety"]["min"].toDouble())
, lion_satiety_max(mConfig["simulation"]["animal"]["lion"]["satiety"]["max"].toDouble())

// Virus
, virus_sparsity(mConfig["simulation"]["virus"]["sparsity"].toDouble())
, virus_initial_quantity(mConfig["simulation"]["virus"]["initial quantity"].toDouble())
, virus_min_quantity_for_infection(mConfig["simulation"]["virus"]["min quantity for infection"].toDouble())
, virus_infection_probability(mConfig["simulation"]["virus"]["infection probability"].toDouble())
, virus_texture_infected(mConfig["simulation"]["virus"]["texture"].toString())
, virus_infection_range(mConfig["simulation"]["virus"]["infection range"].toDouble())

//ImmuneSystem
, immune_health_recovery(mConfig["simulation"]["immune system"]["health recovery"].toDouble())
, immune_health_penalty(mConfig["simulation"]["immune system"]["health penalty"].toDouble())
, immune_defense_effectiveness(mConfig["simulation"]["immune system"]["defense effectiveness"].toDouble())
, immune_defense_random_variability(mConfig["simulation"]["immune system"]["defense variability"].toDouble())
, immune_adaptive_baseline(mConfig["simulation"]["immune system"]["adaptive baseline"].toDouble())

// Genome
, genome_gray_allele_prevalence(mConfig["simulation"]["genome"]["gray allele prevalence"].toDouble())
, genome_mutability_innate_immune_system(mConfig["simulation"]["genome"]["mutability innate immune system"].toDouble())

{
}

// for debugging purposes
void Config::switchDebug(){
	mConfig["debug"] = j::boolean(!mConfig["debug"].toBool());
	simulation_debug = mConfig["debug"].toBool();
}

bool Config::getDebug() const {
return simulation_debug;
}
