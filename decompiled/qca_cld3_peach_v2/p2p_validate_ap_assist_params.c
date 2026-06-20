void *__fastcall p2p_validate_ap_assist_params(
        void *result,
        _BYTE *a2,
        unsigned int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v12; // x8
  unsigned __int64 v14; // x21
  char is_dfs_for_freq; // w0
  unsigned __int64 v16; // x23
  unsigned __int8 v17; // w22
  unsigned __int8 *v18; // x24
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  bool v27; // zf
  unsigned __int64 v28; // x23
  _BYTE *v29; // x20

  _ReadStatusReg(SP_EL0);
  if ( a2[3] == 1 && a2[4] == 1 )
  {
    LODWORD(v12) = (unsigned __int8)a2[6];
    if ( a2[6] )
    {
      if ( (*a2 & 1) == 0
        && (v14 = (unsigned __int64)result,
            is_dfs_for_freq = wlan_reg_is_dfs_for_freq((__int64)result, a3, a4, a5, a6, a7, a8, a9, a10, a11),
            LODWORD(v12) = (unsigned __int8)a2[6],
            (is_dfs_for_freq & 1) != 0)
        && a2[6] )
      {
        v16 = 0;
        v17 = 0;
        v18 = a2 + 16;
        while ( v16 != 11 )
        {
          if ( !wlan_reg_is_6ghz_op_class(v14, *(v18 - 1))
            && (unsigned int)wlan_reg_legacy_chan_to_freq(v14, *v18, v19, v20, v21, v22, v23, v24, v25, v26) == a3
            && *(_DWORD *)(v18 - 7) | *(unsigned __int16 *)(v18 - 3) )
          {
            v27 = *(_DWORD *)(v18 - 7) == -1 && *(__int16 *)(v18 - 3) == -1;
            if ( !v27 && (*(v18 - 7) & 1) == 0 )
            {
              ++v17;
              *(v18 - 8) = 1;
            }
          }
          v12 = (unsigned __int8)a2[6];
          ++v16;
          v18 += 10;
          if ( v16 >= v12 )
          {
            if ( !v17 )
              goto LABEL_22;
            if ( !a2[6] )
            {
              v14 = 0;
              goto LABEL_35;
            }
            v28 = 0;
            v14 = 0;
            v29 = a2 + 7;
            while ( v28 != 10 )
            {
              if ( v29[1] == 1 )
              {
                if ( v28 != v14 )
                {
                  if ( v14 > 0xA )
                    goto LABEL_31;
                  qdf_mem_copy(&a2[10 * v14 + 7], v29, 0xAu);
                  LODWORD(v12) = (unsigned __int8)a2[6];
                }
                ++v14;
              }
              ++v28;
              v29 += 10;
              if ( v28 >= (unsigned int)v12 )
                goto LABEL_32;
            }
            goto LABEL_31;
          }
        }
        do
        {
LABEL_31:
          __break(0x5512u);
LABEL_32:
          ;
        }
        while ( v14 > 0xA );
LABEL_35:
        result = qdf_mem_set(&a2[10 * v14 + 7], 10 * ((unsigned int)v12 - v17), 0);
        a2[6] = v17;
        a2[5] = 1;
      }
      else
      {
LABEL_22:
        result = qdf_mem_set(a2 + 7, (unsigned int)(10 * v12), 0);
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
