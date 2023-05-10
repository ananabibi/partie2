
/*
 * prjsv 2023
 * Marco Antognini & Jamila Sam
 */

#pragma once

#include <string>
#include "JSON/JSON.hpp"
#include <SFML/Graphics.hpp>


class Config
{
private:

  j::Value mConfig;
  bool simulation_debug;
  
public:
  
  Config(const j::Value& cfg);
  
	// enables / disables debug mode
  void switchDebug();
  bool getDebug() const;

  // returns read
  j::Value& getJsonRead(){
    return mConfig;
  }

  j::Value const& getJsonRead() const {
		return mConfig;
	}


	//window
	const double window_simulation_width;
	const double window_simulation_height;
	const double window_stats_height;
  	const double window_control_width;
	const std::string  window_title;
	const int window_antialiasing_level;

	
	// stats
	const double stats_refresh_rate;
	const std::string stats_log_folder = "logs/";
	const std::string stats_log_prefix = "log_";
	const std::string stats_log_header = "# Plot with GNUPLOT : gnuplot -e \"plot for [i=1:6] 'log_0.txt' u i w l title columnheader(i)\"";

	// debug
    const sf::Color debug_text_color = sf::Color::Blue;
    const size_t default_debug_text_size = 30;


	//simulation (general)

	const double  simulation_time_factor;
	const double  simulation_fixed_step;
	const sf::Time  simulation_time_max_dt;
  const std::string simulation_world_texture;
  const std::string simulation_world_debug_texture;
  //	const int simulation_size;
  //	const int world_size;

  // world
  const double world_size;
  const double environment_breeding_delay;
  const double environment_default_temperature;
  const double environment_min_temperature;
  const double environment_max_temperature;

        // living entity
        const std::string entity_texture_tracked = "target.png";
        const double entity_energy_critical = 5;
        const double entity_repulsive_force;

        // bush
        const std::string bush_texture;
        const double bush_initial_energy = 30;
        const double bush_max_energy = 300;
        const double bush_min_energy = 3;
        const double bush_growth_factor = 3;
        const int bush_max_spread_count;
        const int bush_energy_ratio_to_spread;
        const double bush_distance_to_water;
        const double bush_spread_proba;


        // water
        const std::string water_texture;
        const double water_size;
        const double water_evaporation_threshold;
        const double water_evaporation_rate;


        // animal
        const bool animal_random_walk_low_energy;
        const double animal_low_energy_factor;
//        const double animal_safe_distance = 1000;
        const double animal_meal_retention ;
        const float animal_feed_time;
        const float animal_delivery_time;
        const float animal_mating_time;
        const double animal_satiety_min;
        const double animal_satiety_max;
        const double animal_thirst_delay;
        const double animal_thirst_max_duration;
        const double animal_idle_probability;
        const float animal_idle_time_min;
        const float animal_idle_time_max;
        const float animal_base_energy_consumption;
	    const double animal_min_energy;
        const std::string animal_texture_leader = "crown.png";
        const double animal_pregnancy_probability;
        const double distance_attraction_to_leader;
        const double animal_rotation_delay;

        // buffalo
        const double buffalo_max_speed;
        const double buffalo_mass;
        const double buffalo_energy_loss_factor;
        const double buffalo_view_range;
        const double buffalo_view_distance;
        const double buffalo_random_walk_jitter;
        const double buffalo_random_walk_radius;
        const double buffalo_random_walk_distance;
        const sf::Time buffalo_longevity;
        const double buffalo_energy_initial;
        const double buffalo_energy_min_mating_female;
        const double buffalo_energy_min_mating_male;
        const int buffalo_reproduction_min_children;
        const int buffalo_reproduction_max_children;
        const double buffalo_reproduction_gestation_time;
        const double buffalo_energy_loss_female_per_child;
        const double buffalo_energy_loss_mating_male;
        const std::string buffalo_texture_black_male;
        const std::string buffalo_texture_black_female;
        const std::string buffalo_texture_gray_male;
        const std::string buffalo_texture_gray_female;
        const double buffalo_size;
        const double buffalo_energy_bite;


        // lion
        const double lion_max_speed;
        const double lion_mass;
        const double lion_energy_loss_factor;
        const double lion_view_range;
        const double lion_view_distance;
        const double lion_random_walk_jitter;
        const double lion_random_walk_radius;
        const double lion_random_walk_distance;
        const sf::Time lion_longevity;
        const double lion_energy_initial;
        const double lion_energy_min_mating_female;
        const double lion_energy_min_mating_male;
        const int lion_reproduction_min_children;
        const int lion_reproduction_max_children;
        const double lion_reproduction_gestation_time;
        const double lion_energy_loss_female_per_child;
        const double lion_energy_loss_mating_male;
        const std::string lion_texture_male;
        const std::string lion_texture_female;
        const double lion_size;
//        const double lion_energy_bite;
        const double lion_idle_probability;
        const float lion_idle_time_min;
        const float lion_idle_time_max;
        const double lion_satiety_min;
        const double lion_satiety_max;

        // Virus
        const double virus_sparsity; // probability of component in mProfile to be non-zero
        const double virus_initial_quantity; // initial quantity of virus when infection occurs
        const double virus_min_quantity_for_infection; // minimal quantity of virus needed to infect other animals
        // TODO possible extension : make it dt-dependent
        const double virus_infection_probability; // probability of infecting an animal in range at each step.
        const std::string virus_texture_infected;
        const double virus_infection_range; // range within which the virus may propagate to another animal
        const double virus_max = 200; // maximal quantity the virus can reach
        const double virus_growth_rate = 1.3; // growth rate of the virus (*dt*saturation term)

        // ImmuneSystem
        const double immune_health_recovery; // speed at which health recovers when virus has been eradicated
        const double immune_health_penalty; // health loss due to virus quantity (*dt)
        const double immune_defense_effectiveness; // virus quantity reduction (*score*dt)
        const double immune_defense_random_variability; // random score added to each component of the score computation
            // -- >baseline mPwr
        const double immune_adaptive_baseline;
        const double immune_adaptive_rate = 0.05; // determines speed at which the immune system adapts (*dt*virus profile)
        const double immune_health_max = 100; // max health of the animals


        // Genome
        const double genome_gray_allele_prevalence;
        const double genome_mutability_innate_immune_system;


};


