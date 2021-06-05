/*==========================LICENSE NOTICE==========================*/
/*
 * Copyright (c) 2021 Vidcentum R&D Pvt Ltd, India.
 * License: Refer to LICENSE file of the software package.
 * Email: support@vidcentum.com
 * Website: https://vidcentum.com
*/
/*========================END LICENSE NOTICE========================*/

#include <iostream>
#include "compact_si_units.h"

namespace si_units_compact_representation_api {
  
  std::map<std::string, std::string>
  g_si_unit_factor_display_sym_map_ {
    
    /* name       -         gui/print symbol */
    { SI_PREFIX_DECA_STR,   "d" },
    { SI_PREFIX_HECTO_STR,  "h" },
    { SI_PREFIX_KILO_STR,   "k" },
    { SI_PREFIX_MEGA_STR,   "M" },
    { SI_PREFIX_GIGA_STR,   "G" },
    { SI_PREFIX_TERA_STR,   "T" },
    { SI_PREFIX_PETA_STR,   "P" },
    { SI_PREFIX_EXA_STR,    "E" },
    { SI_PREFIX_ZETTA_STR,  "Z" },
    { SI_PREFIX_YOTTA_STR,  "Y" },
    { SI_PREFIX_DECI_STR,   "d" },
    { SI_PREFIX_CENTI_STR,  "c" },
    { SI_PREFIX_MILLI_STR,  "m" },
    { SI_PREFIX_MICRO_STR,  "µ" },
    { SI_PREFIX_NANO_STR,   "n" },
    { SI_PREFIX_PICO_STR,   "p" },
    { SI_PREFIX_FEMTO_STR,  "f" },
    { SI_PREFIX_ATTO_STR,   "a" },
    { SI_PREFIX_ZEPTO_STR,  "z" },
    { SI_PREFIX_YOCTO_STR,  "y" }
    
  };

  std::map<std::string, std::string>
  g_si_unit_quantity_display_sym_map_ {
    
    /* name                     -                gui/print symbol */
    { SI_METER_STR,                              "m"   },
    { SI_KILOGRAM_STR,                           "kg"  },
    { SI_SECOND_STR,                             "s"   },
    { SI_AMPERE_STR,                             "A"   },
    { SI_KELVIN_STR,                             "K"   },
    { SI_MOLE_STR,                               "mol" },
    { SI_CANDELA_STR,                            "cd"  },
    { SI_RADIAN_STR,                             "rad" },
    { SI_STERADIAN_STR,                          "sr"  },
    { SI_HERTZ_STR,                              "Hz"  },
    { SI_AREA_STR,                               "m\u00B2"           }, // m^2
    { SI_VOLUME_STR,                             "m\u00B3"           }, // m^3
    { SI_ACCELERATION_STR,                       "m s\u207B\u00B2"   }, // m/s^2
    { SI_WAVE_NUMBER_STR,                        "m\u207B\u00B9"     }, // 1/m
    { SI_DENSITY_STR,                            "kg m\u207B\u00B3"  }, // kg/m^3
    { SI_SPECIFIC_VOLUME_STR,                    "m\u00B3 kg\u207B\u00B9" }, // m^3/kg
    { SI_CURRENT_DENSITY_STR,                    "A m\u207B\u00B2"   }, // A/m^2 
    { SI_MAGNETIC_FIELD_STRENGTH_STR,            "A m\u207B\u00B9"   }, // A/m  
    { SI_AMOUNT_OF_SUBSTANCE_CONCENTRATION_STR,  "mol m\u207B\u00B3" }, // Mol/m^3 
    { SI_LUMINANCE_STR,                          "cd m\u207B\u00B2"  }, // cd/m^2 
    { SI_NEWTON_STR,                             "N"   },
    { SI_PASCAL_STR,                             "Pa"  },
    { SI_JOULE_STR,                              "J"   },
    { SI_WATT_STR,                               "W"   },
    { SI_COULOMB_STR,                            "C"   },
    { SI_VOLT_STR,                               "V"   },
    { SI_FARAD_STR,                              "F"   },
    { SI_OHM_STR,                                "Ω"   },
    { SI_SIEMENS_STR,                            "S"   },
    { SI_WEBER_STR,                              "Wb"  },
    { SI_TESLA_STR,                              "T"   },
    { SI_HENRY_STR,                              "H"   },
    { SI_DEGREE_CELSIUS_STR,                     "°C"  },
    { SI_LUMEN_STR,                              "lm"  },
    { SI_LUX_STR,                                "lx"  },
    { SI_NOISE_SPECTRAL_DENSITY_STR,             "V/√Hz"   }, // m^2.kg.s^–5/2.A^–1
    { SI_MASS_FRACTION_STR,                      "mol/mol" },
    { SI_STRAIN_STR,                             "m/m" },
    { SI_RADIATED_POWER_QUANTITY_STR,            "Bel" }, // Bel (log10 W/W) W=m^2.kg.s^–3
    { SI_COUNT_STR,                              ""    }, // Depends on the deployment.
    { SI_SWITCH_POSITIONS_STR,                   "ON/OFF"  }
      
  };
  
  Units::Units ()
  {
    interpretation  = PUI_SI_UNITS;
    radians         = 128;
    steradians      = 128;
    meters          = 128;
    kilograms       = 128;
    seconds         = 128;
    amperes         = 128;
    kelvins         = 128;
    moles           = 128;
    candelas        = 128;
    extension       = 128;
  }
  
  Units::Units (const Units& c)
  {
    interpretation  = c.interpretation;
    radians         = c.radians;
    steradians      = c.steradians;
    meters          = c.meters;
    kilograms       = c.kilograms;
    seconds         = c.seconds;
    amperes         = c.amperes;
    kelvins         = c.kelvins;
    moles           = c.moles;
    candelas        = c.candelas;
    extension       = c.extension;
  }
  
  Units& Units::operator = (const Units& c)
  {
    interpretation  = c.interpretation;
    radians         = c.radians;
    steradians      = c.steradians;
    meters          = c.meters;
    kilograms       = c.kilograms;
    seconds         = c.seconds;
    amperes         = c.amperes;
    kelvins         = c.kelvins;
    moles           = c.moles;
    candelas        = c.candelas;
    extension       = c.extension;
    
    return *this;
  }
  
  const bool Units::operator == (const Units& c) const
  {
    if ((interpretation  == c.interpretation)
        && (radians      == c.radians)
        && (steradians   == c.steradians)
        && (meters       == c.meters)
        && (kilograms    == c.kilograms)
        && (seconds      == c.seconds)
        && (amperes      == c.amperes)
        && (kelvins      == c.kelvins)
        && (moles        == c.moles)
        && (candelas     == c.candelas)
        && (extension    == c.extension)) {
      
      return true;
    }    
    return false;
  }
  
  compact_si_units_t::compact_si_units_t(double _val, const std::string& _factor, const Units& _units)
  {
    measurement_val_ = _val;
    si_factor_ = _factor;
    si_units_  = _units;
  }
  
  compact_si_units_t::compact_si_units_t (const compact_si_units_t& c)
  {
    measurement_val_ = c.measurement_val_;
    si_factor_ = c.si_factor_;
    si_units_  = c.si_units_;
  }
  
  compact_si_units_t& compact_si_units_t::operator = (const compact_si_units_t& c)
  {
    measurement_val_ = c.measurement_val_;
    si_factor_ = c.si_factor_;
    si_units_  = c.si_units_;
    
    return *this;
  }
  
  void si_units_assert_if(bool _b) 
  { 
#ifdef VC_SI_UNITS_ASSERT
    if(!_b) exit(0);
#endif
  }
  
  // Decodes the given units. 
  // Returns  true and a pair of unit name and its gui / display string.
  //          false and a pair of empty strings.
  std::tuple<bool, std::pair<std::string, std::string>> decode_units(const Units& _u)
  {
    if (is_meter(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_METER_STR, g_si_unit_quantity_display_sym_map_.at(SI_METER_STR)}};
      
      return du;
    }
    if (is_kilogram(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_KILOGRAM_STR, g_si_unit_quantity_display_sym_map_.at(SI_KILOGRAM_STR)}};
      
      return du;
    }
    
    if (is_second(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_SECOND_STR, g_si_unit_quantity_display_sym_map_.at(SI_SECOND_STR)}};
      
      return du;
    }
    
    if (is_ampere(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_AMPERE_STR, g_si_unit_quantity_display_sym_map_.at(SI_AMPERE_STR)}};
      
      return du;
    }
    
    if (is_kelvin(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_KELVIN_STR, g_si_unit_quantity_display_sym_map_.at(SI_KELVIN_STR)}};
      
      return du;
    }
    
    if (is_mole(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_MOLE_STR, g_si_unit_quantity_display_sym_map_.at(SI_MOLE_STR)}};
      
      return du;
    }
    
    if (is_candela(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_CANDELA_STR, g_si_unit_quantity_display_sym_map_.at(SI_CANDELA_STR)}};
      
      return du;
    }
    
    if (is_radian(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_RADIAN_STR, g_si_unit_quantity_display_sym_map_.at(SI_RADIAN_STR)}};
      
      return du;
    }
    
    if (is_steradian(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_STERADIAN_STR, g_si_unit_quantity_display_sym_map_.at(SI_STERADIAN_STR)}};
      
      return du;
    }
        
    if (is_hertz(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_HERTZ_STR, g_si_unit_quantity_display_sym_map_.at(SI_HERTZ_STR)}};
      
      return du;
    }
    
    if (is_area(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_AREA_STR, g_si_unit_quantity_display_sym_map_.at(SI_AREA_STR)}};
      
      return du;
    }
    
    if (is_volume(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_VOLUME_STR, g_si_unit_quantity_display_sym_map_.at(SI_VOLUME_STR)}};
      
      return du;
    }
    
    if (is_acceleration(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_ACCELERATION_STR, g_si_unit_quantity_display_sym_map_.at(SI_ACCELERATION_STR)}};
      
      return du;
    }
    if (is_wave_number(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_WAVE_NUMBER_STR, g_si_unit_quantity_display_sym_map_.at(SI_WAVE_NUMBER_STR)}};
      
      return du;
    }
    
    if (is_density(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_DENSITY_STR, g_si_unit_quantity_display_sym_map_.at(SI_DENSITY_STR)}};
      
      return du;
    }
    
    if (is_specific_volume(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_SPECIFIC_VOLUME_STR, g_si_unit_quantity_display_sym_map_.at(SI_SPECIFIC_VOLUME_STR)}};
      
      return du;
    }
    
    if (is_current_density(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_CURRENT_DENSITY_STR, g_si_unit_quantity_display_sym_map_.at(SI_CURRENT_DENSITY_STR)}};
      
      return du;
    }
    
    if (is_magnetic_field_strength(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_MAGNETIC_FIELD_STRENGTH_STR, g_si_unit_quantity_display_sym_map_.at(SI_MAGNETIC_FIELD_STRENGTH_STR)}};
      
      return du;
    }
    
    if (is_amount_of_substance_concentration(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_AMOUNT_OF_SUBSTANCE_CONCENTRATION_STR, g_si_unit_quantity_display_sym_map_.at(SI_AMOUNT_OF_SUBSTANCE_CONCENTRATION_STR)}};
      
      return du;
    }
    
    if (is_luminance(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_LUMINANCE_STR, g_si_unit_quantity_display_sym_map_.at(SI_LUMINANCE_STR)}};
      
      return du;
    }
    
    if (is_newton(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_NEWTON_STR, g_si_unit_quantity_display_sym_map_.at(SI_NEWTON_STR)}};
      
      return du;
    }
    
    if (is_pascal(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_PASCAL_STR, g_si_unit_quantity_display_sym_map_.at(SI_PASCAL_STR)}};
      
      return du;
    }
    
    if (is_joule(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_JOULE_STR, g_si_unit_quantity_display_sym_map_.at(SI_JOULE_STR)}};
      
      return du;
    }
    
    if (is_watt(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_WATT_STR, g_si_unit_quantity_display_sym_map_.at(SI_WATT_STR)}};
      
      return du;
    }
    
    if (is_coulomb(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_COULOMB_STR, g_si_unit_quantity_display_sym_map_.at(SI_COULOMB_STR)}};
      
      return du;
    }
    
    if (is_volt(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_VOLT_STR, g_si_unit_quantity_display_sym_map_.at(SI_VOLT_STR)}};
      
      return du;
    }
    
    if (is_farad(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_FARAD_STR, g_si_unit_quantity_display_sym_map_.at(SI_FARAD_STR)}};
      
      return du;
    }
    
    if (is_ohm(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_OHM_STR, g_si_unit_quantity_display_sym_map_.at(SI_OHM_STR)}};
      
      return du;
    }
    
    if (is_siemens(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_SIEMENS_STR, g_si_unit_quantity_display_sym_map_.at(SI_SIEMENS_STR)}};
      
      return du;
    }
    
    if (is_weber(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_WEBER_STR, g_si_unit_quantity_display_sym_map_.at(SI_WEBER_STR)}};
      
      return du;
    }
    
    if (is_tesla(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_TESLA_STR, g_si_unit_quantity_display_sym_map_.at(SI_TESLA_STR)}};
      
      return du;
    }
    
    if (is_henry(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_HENRY_STR, g_si_unit_quantity_display_sym_map_.at(SI_HENRY_STR)}};
      
      return du;
    }
    
    if (is_degree_celsius(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_DEGREE_CELSIUS_STR, g_si_unit_quantity_display_sym_map_.at(SI_DEGREE_CELSIUS_STR)}};
      
      return du;
    }
    
    if (is_lumen(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_LUMEN_STR, g_si_unit_quantity_display_sym_map_.at(SI_LUMEN_STR)}};
      
      return du;
    }
    
    if (is_lux(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_LUX_STR, g_si_unit_quantity_display_sym_map_.at(SI_LUX_STR)}};
      
      return du;
    }
    
    if (is_count(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_COUNT_STR, g_si_unit_quantity_display_sym_map_.at(SI_COUNT_STR)}};
      
      return du;
    }
    
    if (is_noise_spectral_density(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_NOISE_SPECTRAL_DENSITY_STR, g_si_unit_quantity_display_sym_map_.at(SI_NOISE_SPECTRAL_DENSITY_STR)}};
      
      return du;
    }
    
    if (is_mass_fraction(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_MASS_FRACTION_STR, g_si_unit_quantity_display_sym_map_.at(SI_MASS_FRACTION_STR)}};
      
      return du;
    }
    
    if (is_strain(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_STRAIN_STR, g_si_unit_quantity_display_sym_map_.at(SI_STRAIN_STR)}};
      
      return du;
    }
    
    if (is_radiated_power_quantity(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_RADIATED_POWER_QUANTITY_STR, g_si_unit_quantity_display_sym_map_.at(SI_RADIATED_POWER_QUANTITY_STR)}};
      
      return du;
    }
    
    if (is_switch_position(_u)) {
      std::tuple<bool, std::pair<std::string, std::string>> 
      du{true, {SI_SWITCH_POSITIONS_STR, g_si_unit_quantity_display_sym_map_.at(SI_SWITCH_POSITIONS_STR)}};
      
      return du;
    }
    
    std::pair<bool, std::pair<std::string, std::string>> du {false, {"", ""}};
    return du;
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                             Distance (meter, m)                             |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  1  |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 130 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_meter_unit() 
  {
    Units u;
    
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 130; // (2 * <exponent of meters>) + 128
    
    return u;
  }
  bool is_meter(const Units& _u)
  {
    return (_u == encode_meter_unit());
  }

  /*
    +-----------------------------------------------------------------------------+
    |                             Kilogram (kg)                                   |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  1  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 130 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_kilogram_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128 
    
    return u;
  }
  bool is_kilogram(const Units& _u)
  {
    return (_u == encode_kilogram_unit());
  }

  /*
    +-----------------------------------------------------------------------------+
    |                               Time (second, s)                              |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  1  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 130 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_second_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.seconds         = 130; // (2 * <exponent of seconds>) + 128
    
    return u;
  }
  bool is_second(const Units& _u)
  {
    return (_u == encode_second_unit());
  }

  /*
    +-----------------------------------------------------------------------------+
    |                         Electric current (Ampere, A)                        |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  0  |  1  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 128 | 130 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_ampere_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.amperes         = 130; // (2 * <exponent of amperes>) + 128
    
    return u;
  }
  bool is_ampere(const Units& _u)
  {
    return (_u == encode_ampere_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                    Thermodynamic temperature (Kelvin, K)                    |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 128 | 128 | 130 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_kelvin_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.kelvins         = 130; // (2 * <exponent of kelvins>) + 128
    
    return u;
  }
  bool is_kelvin(const Units& _u)
  {
    return (_u == encode_kelvin_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                       Amount of substance (Mole, mol)                       |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 128 | 128 | 128 | 130 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_mole_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.moles           = 130; // (2 * <exponent of moles>) + 128
    
    return u;
  }
  bool is_mole(const Units& _u)
  {
    return (_u == encode_mole_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                       Luminous intensity (Candela, cd)                      |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 128 | 128 | 128 | 128 | 130 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_candela_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.candelas        = 130; // (2 * <exponent of candelas>) + 128
    
    return u;
  }
  bool is_candela(const Units& _u)
  {
    return (_u == encode_candela_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                          Plane angle (Radians, rad)                         |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  1  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 130 | 128 | 128 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_radian_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.radians         = 130; // (2 * <exponent of radians>) + 128
    
    return u;
  }
  bool is_radian(const Units& _u)
  {
    return (_u == encode_radian_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                         Solid angle (Steradian, sr)                         |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  1  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 130 | 128 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_steradian_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.steradians      = 130; // (2 * <exponent of steradians>) + 128
    
    return u;
  }
  bool is_steradian(const Units& _u)
  {
    return (_u == encode_steradian_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                         Frequency (Hertz, Hz, s^–1)                         |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  -1 |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 126 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_hertz_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.seconds         = 126; // (2 * <exponent of seconds>) + 128
    
    return u;
  }
  bool is_hertz(const Units& _u)
  {
    return (_u == encode_hertz_unit());
  }

  /*
    +-----------------------------------------------------------------------------+
    |                        Area (square meter, area, m^2)                       |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_area_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    
    return u;
  }
  bool is_area(const Units& _u)
  {
    return (_u == encode_area_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                      Volume (cubic meter, volume, m^3)                      |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  3  |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 134 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_volume_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 134; // (2 * <exponent of meters>) + 128
    
    return u;
  }
  bool is_volume(const Units& _u)
  {
    return (_u == encode_volume_unit());
  }
  /*
    +-----------------------------------------------------------------------------+
    |         Acceleration (meter per second squared, acceleration, m/s^2)        |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  1  |  0  |  -2 |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 130 | 128 | 124 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_acceleration_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 130; // (2 * <exponent of meters>) + 128
    u.seconds         = 124; // (2 * <exponent of seconds>) + 128
    
    return u;
  }
  bool is_acceleration(const Units& _u)
  {
    return (_u == encode_acceleration_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |               Wave number (reciprocal meter, wave_number, 1/m)              |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -1 |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 126 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_wave_number_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 126; // (2 * <exponent of meters>) + 128
    
    return u;
  }
  bool is_wave_number(const Units& _u)
  {
    return (_u == encode_wave_number_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |               Mass density(density) (kilogram per cubic meter)              |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -3 |  1  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 122 | 130 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_density_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 122; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    return u;
  }
  bool is_density(const Units& _u)
  {
    return (_u == encode_density_unit());
  }
    
  /*
    +-----------------------------------------------------------------------------+
    |     Specific volume (cubic meter per kilogram, specific_volume, m^3/kg)     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  3  |  -1 |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 134 | 126 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_specific_volume_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 134; // (2 * <exponent of meters>) + 128
    u.kilograms       = 126; // (2 * <exponent of kilograms>) + 128
    return u;
  }
  bool is_specific_volume(const Units& _u)
  {
    return (_u == encode_specific_volume_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |      Current density (ampere per square meter, current_density, A/m^2)      |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -2 |  0  |  0  |  1  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 124 | 128 | 128 | 130 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_current_density_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 124; // (2 * <exponent of meters>) + 128
    u.amperes         = 130; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_current_density(const Units& _u)
  {
    return (_u == encode_current_density_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |   Magnetic field strength (ampere per meter, magnetic_field_strength, A/m)  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -1 |  0  |  0  |  1  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 126 | 128 | 128 | 130 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_magnetic_field_strength_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 126; // (2 * <exponent of meters>) + 128
    u.amperes         = 130; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_magnetic_field_strength(const Units& _u)
  {
    return (_u == encode_magnetic_field_strength_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |      Amount-of-substance concentration (mole per cubic meter, Mol/m^3)      |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -3 |  0  |  0  |  0  |  0  |  1  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 122 | 128 | 128 | 128 | 128 | 130 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_amount_of_substance_concentration_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 122; // (2 * <exponent of meters>) + 128
    u.moles           = 130; // (2 * <exponent of moles>) + 128
    return u;
  }
  bool is_amount_of_substance_concentration(const Units& _u)
  {
    return (_u == encode_amount_of_substance_concentration_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                 Luminance (candela per square meter, cd/m^2)                |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -2 |  0  |  0  |  0  |  0  |  0  |  1  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 124 | 128 | 128 | 128 | 128 | 128 | 130 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_luminance_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 124; // (2 * <exponent of meters>) + 128
    u.candelas        = 130; // (2 * <exponent of candelas>) + 128
    return u;
  }
  bool is_luminance(const Units& _u)
  {
    return (_u == encode_luminance_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                        Force (Newton, N,  m.kg.s^–2)                        |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  1  |  1  |  -2 |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 130 | 130 | 124 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_newton_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 130; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 124; // (2 * <exponent of seconds>) + 128
    return u;
  }
  bool is_newton(const Units& _u)
  {
    return (_u == encode_newton_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |            Pressure, stress (Pascal, Pa, N/m^2, SI: m^–1.kg.s^–2)           |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -1 |  1  |  -2 |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 126 | 130 | 124 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_pascal_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 126; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 124; // (2 * <exponent of seconds>) + 128
    return u;
  }
  bool is_pascal(const Units& _u)
  {
    return (_u == encode_pascal_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |       Energy, work, quantity of heat (Joule, J, N.m, SI: m^2.kg.s^–2)       |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  1  |  -2 |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 | 124 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_joule_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 124; // (2 * <exponent of seconds>) + 128
    return u;
  }
  bool is_joule(const Units& _u)
  {
    return (_u == encode_joule_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |             Power, radiant flux (Watt, W, J/s, SI: m^2.kg.s^–3)             |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  1  |  -3 |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 | 122 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_watt_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 122; // (2 * <exponent of seconds>) + 128
    return u;
  }
  bool is_watt(const Units& _u)
  {
    return (_u == encode_watt_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                      Electric charge (Coulomb, C, s.A)                      |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  1  |  1  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 130 | 130 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_coulomb_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.seconds         = 130; // (2 * <exponent of seconds>) + 128
    u.amperes         = 130; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_coulomb(const Units& _u)
  {
    return (_u == encode_coulomb_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |        Electric potential, EMF etc., (Volt, V, W/A, m^2.kg.s^–3.A^–1)       |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  1  |  -3 |  -1 |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 | 122 | 126 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_volt_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 122; // (2 * <exponent of seconds>) + 128
    u.amperes         = 126; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_volt(const Units& _u)
  {
    return (_u == encode_volt_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |               Capacitance (Farad, F, C/V, m^–2.kg^–1.s^4.A^2)               |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -2 |  -1 |  4  |  2  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 124 | 126 | 136 | 132 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_farad_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 124; // (2 * <exponent of meters>) + 128
    u.kilograms       = 126; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 136; // (2 * <exponent of seconds>) + 128
    u.amperes         = 132; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_farad(const Units& _u)
  {
    return (_u == encode_farad_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |             Electric resistance (Ohm, Ω, V/A, m^2.kg.s^–3.A^–2)             |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  1  |  -3 |  -2 |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 | 122 | 124 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_ohm_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 122; // (2 * <exponent of seconds>) + 128
    u.amperes         = 124; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_ohm(const Units& _u)
  {
    return (_u == encode_ohm_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |          Electric conductance (Siemens, S, A/V, m^–2.kg^–1.s^3.A^2)         |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  -2 |  -1 |  3  |  2  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 124 | 126 | 134 | 132 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_siemens_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 124; // (2 * <exponent of meters>) + 128
    u.kilograms       = 126; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 134; // (2 * <exponent of seconds>) + 128
    u.amperes         = 132; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_siemens(const Units& _u)
  {
    return (_u == encode_siemens_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |               Magnetic flux (Weber, Wb, V.s, m^2.kg.s^–2.A^–1)              |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  1  |  -2 |  -1 |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 | 124 | 126 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_weber_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 124; // (2 * <exponent of seconds>) + 128
    u.amperes         = 126; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_weber(const Units& _u)
  {
    return (_u == encode_weber_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |             Magnetic flux density (Tesla, Wb/m^2, kg.s^–2.A^–1)             |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  1  |  -2 |  -1 |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 130 | 124 | 126 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_tesla_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 124; // (2 * <exponent of seconds>) + 128
    u.amperes         = 126; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_tesla(const Units& _u)
  {
    return (_u == encode_tesla_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                Inductance (Henry, H, Wb/A, m^2.kg.s^–2.A^–2)                |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  1  |  -2 |  -2 |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 | 124 | 124 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_henry_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 124; // (2 * <exponent of seconds>) + 128
    u.amperes         = 124; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_henry(const Units& _u)
  {
    return (_u == encode_henry_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |               Celsius temperature (degree_celsius, °C, SI: K)               |
    |   Note: The temperature units should be determined with the system design.  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 128 | 128 | 130 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_degree_celsius_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.kelvins         = 130; // (2 * <exponent of kelvins>) + 128
    return u;
  }
  bool is_degree_celsius(const Units& _u)
  {
    return (_u == encode_degree_celsius_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                       Luminous flux (Lumen, lm, cd.sr)                      |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  1  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 130 | 128 | 128 | 128 | 128 | 128 | 128 | 130 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_lumen_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.steradians      = 130; // (2 * <exponent of steradians>) + 128
    u.candelas        = 130; // (2 * <exponent of candelas>) + 128
    return u;
  }
  bool is_lumen(const Units& _u)
  {
     return (_u == encode_lumen_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                  Illuminance (Lux, lx, lm/m^2, m^–2.cd.sr)                  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  1  |  -2 |  0  |  0  |  0  |  0  |  0  |  1  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 130 | 124 | 128 | 128 | 128 | 128 | 128 | 130 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_lux_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 124; // (2 * <exponent of meters>) + 128
    u.steradians      = 130; // (2 * <exponent of steradians>) + 128
    u.candelas        = 130; // (2 * <exponent of candelas>) + 128
    return u;
  }
  bool is_lux(const Units& _u)
  {
    return (_u == encode_lux_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------------------+
    |                                          Counts                                         |
    | (E.g. If a transducer counts the number of items passing through a packaging gate etc.) |
    +------------+-------------+------+------+------+------+------+------+------+------+------+
    |            |     Enum    |  rad |  sr  |   m  |  kg  |   s  |   A  |   K  |  mol |  cd  |
    |            |  (Manifest) |      |      |      |      |      |      |      |      |      |
    +------------+-------------+------+------+------+------+------+------+------+------+------+
    |  Exponent  |      0      |   0  |   0  |   0  |   0  |   0  |   0  |   0  |   0  |   0  |
    +------------+-------------+------+------+------+------+------+------+------+------+------+
    |   Decimal  |             |  128 |  128 |  128 |  128 |  128 |  128 |  128 |  128 |  128 |
    +------------+-------------+------+------+------+------+------+------+------+------+------+
  */
  const Units encode_count_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    return u;
  }
  bool is_count(const Units& _u)
  {
    return (_u == encode_count_unit());
  }
  
  /*
    +------------------------------------------------------------------------------+
    | Noise spectral density (volts per root Hertz, V/√Hz, SI: m^2.kg.s^–5/2.A^–1) |
    +----------+------------+-----+-----+-----+-----+------+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |   s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |      |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+------+-----+-----+-----+-----+
    | Exponent |      0     |  0  |  0  |  2  |  1  | -5/2 |  -1 |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+------+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 |  123 | 126 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+------+-----+-----+-----+-----+
  */
  const Units encode_noise_spectral_density_unit()
  {
    Units u;
    u.interpretation  = PUI_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 123; // (2 * <exponent of seconds>) + 128
    u.amperes         = 126; // (2 * <exponent of amperes>) + 128
    return u;
  }
  bool is_noise_spectral_density(const Units& _u)
  {
    return (_u == encode_noise_spectral_density_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                           Mass fraction (mol/mol)                           |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      1     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  1  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 128 | 128 | 128 | 130 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_mass_fraction_unit()
  {
    Units u;
    u.interpretation  = PUI_RATIO_SI_UNITS;
    u.moles           = 130; // (2 * <exponent of moles>) + 128
    
    return u;
  }
  bool is_mass_fraction(const Units& _u)
  {
    return (_u == encode_mass_fraction_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |                                 strain (m/m)                                |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      1     |  0  |  0  |  1  |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 130 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_strain_unit()
  {
    Units u;
    u.interpretation  = PUI_RATIO_SI_UNITS;
    u.meters          = 130; // (2 * <exponent of meters>) + 128
    
    return u;
  }
  bool is_strain(const Units& _u)
  {
    return (_u == encode_strain_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |           Radiated Power quantity—Bel (log10 W/W) W = m^2.kg.s^–3           |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      3     |  0  |  0  |  2  |  1  |  -3 |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 132 | 130 | 122 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_radiated_power_quantity_unit()
  {
    Units u;
    u.interpretation  = PUI_LOG10_RATIO_SI_UNITS;
    u.meters          = 132; // (2 * <exponent of meters>) + 128
    u.kilograms       = 130; // (2 * <exponent of kilograms>) + 128
    u.seconds         = 122; // (2 * <exponent of seconds>) + 128
    return u;
  }
  bool is_radiated_power_quantity(const Units& _u)
  {
    return (_u == encode_radiated_power_quantity_unit());
  }
  
  /*
    +-----------------------------------------------------------------------------+
    |          Switch positions (e.g. “on,” “off,” “up,” “closed,” etc.,)         |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |          |    Enum    | rad |  sr |  m  |  kg |  s  |  A  |  K  | mol |  cd |
    |          | (Manifest) |     |     |     |     |     |     |     |     |     |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    | Exponent |      4     |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |  0  |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
    |  Decimal |            | 128 | 128 | 128 | 128 | 128 | 128 | 128 | 128 | 128 |
    +----------+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+
  */
  const Units encode_switch_position_unit()
  {
    Units u;
    u.interpretation  = PUI_DIGITAL_DATA;
    return u;
  }
  bool is_switch_position(const Units& _u)
  {
    return (_u == encode_switch_position_unit());
  }
  
  std::tuple<bool, std::pair<std::string, std::string>> operator""_unit_sym(const char* _un, size_t _sz)
  {
    try {
      std::tuple<bool, std::pair<std::string, std::string>>
      du{true, {_un, g_si_unit_quantity_display_sym_map_.at(_un)}};
      return du;
    } catch (std::out_of_range& oee) {
      std::tuple<bool, std::pair<std::string, std::string>>
      du{false, {_un, ""}};
      return du;
    }
  }
  
} // END of si_units_compact_representation_api namespace.
