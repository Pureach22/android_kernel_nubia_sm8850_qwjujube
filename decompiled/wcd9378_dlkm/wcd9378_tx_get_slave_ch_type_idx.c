__int64 __fastcall wcd9378_tx_get_slave_ch_type_idx(__int64 a1, int *a2)
{
  __int64 result; // x0
  char *v5; // x8
  int v6; // w8

  result = strnstr(a1, "ADC1", 5);
  if ( result )
  {
    v5 = (char *)&wcd9378_swr_slv_tx_ch_idx;
  }
  else
  {
    result = strnstr(a1, "ADC2", 5);
    if ( result )
    {
      v5 = (char *)&unk_17C9A;
    }
    else
    {
      result = strnstr(a1, "ADC3", 5);
      if ( result )
      {
        v5 = (char *)&unk_17C9C;
      }
      else
      {
        result = strnstr(a1, "ADC4", 5);
        if ( result )
        {
          v5 = (char *)&unk_17C9E;
        }
        else
        {
          result = strnstr(a1, "DMIC0", 6);
          if ( result )
          {
            v5 = (char *)&unk_17CA0;
          }
          else
          {
            result = strnstr(a1, "DMIC1", 6);
            if ( result )
            {
              v5 = (char *)&unk_17CA2;
            }
            else
            {
              result = strnstr(a1, "MBHC", 5);
              if ( result )
              {
                v5 = (char *)&unk_17CA4;
              }
              else
              {
                result = strnstr(a1, "DMIC2", 6);
                if ( result )
                {
                  v5 = (char *)&unk_17CA6;
                }
                else
                {
                  result = strnstr(a1, "DMIC3", 6);
                  if ( result )
                  {
                    v5 = "%\a&\b'\t(\n)\v";
                  }
                  else
                  {
                    result = strnstr(a1, "DMIC4", 6);
                    if ( result )
                    {
                      v5 = "&\b'\t(\n)\v";
                    }
                    else
                    {
                      result = strnstr(a1, "DMIC5", 6);
                      if ( !result )
                      {
                        result = printk(&unk_134C2, "wcd9378_tx_get_slave_ch_type_idx");
                        v6 = -22;
                        goto LABEL_24;
                      }
                      v5 = "'\t(\n)\v";
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
  v6 = (unsigned __int8)v5[1];
LABEL_24:
  *a2 = v6;
  return result;
}
