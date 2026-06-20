unsigned __int64 __fastcall gen8_counter_read(_QWORD *a1)
{
  int v2; // w0
  int v3; // w21
  unsigned int v4; // w20

  kgsl_regmap_write(a1 + 1650, 1);
  kgsl_regmap_write(a1 + 1650, 1);
  __dsb(0xEu);
  if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
  {
    _const_udelay(42950);
    if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
    {
      _const_udelay(42950);
      if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
      {
        _const_udelay(42950);
        if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
        {
          _const_udelay(42950);
          if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
          {
            _const_udelay(42950);
            if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
            {
              _const_udelay(42950);
              if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
              {
                _const_udelay(42950);
                if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
                {
                  _const_udelay(42950);
                  if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
                  {
                    _const_udelay(42950);
                    if ( (kgsl_regmap_read(a1 + 1650) & 1) == 0 )
                    {
                      _const_udelay(42950);
                      v2 = kgsl_regmap_read(a1 + 1650);
                      if ( (v2 & 1) == 0 )
                      {
                        v3 = v2;
                        if ( (unsigned int)__ratelimit(&gen8_rbbm_perfctr_flush__rs, "gen8_rbbm_perfctr_flush") )
                          dev_err(*a1, "Perfcounter flush timed out: status=0x%08x\n", v3);
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  v4 = kgsl_regmap_read(a1 + 1650);
  return v4 | (unsigned __int64)(kgsl_regmap_read(a1 + 1650) << 32);
}
