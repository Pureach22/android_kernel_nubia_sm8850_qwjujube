__int64 __fastcall reg_get_pwrmode_chan_list(
        __int64 a1,
        _WORD *a2,
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
  _BYTE *pdev_obj; // x0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  _BYTE *v22; // x21
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _WORD *v31; // x20
  char *v32; // x21
  __int64 v33; // x27
  unsigned int v34; // w8
  int v35; // w9
  int v36; // w10
  _DWORD *v37; // x11
  __int16 v38; // w12
  __int16 v39; // w8
  int v40; // w9
  __int16 v41; // w8
  __int64 v42; // x20
  __int64 result; // x0
  __int64 v44; // x20
  __int64 v45; // x20
  _DWORD dest[67]; // [xsp+4h] [xbp-11Ch] BYREF
  __int64 v47; // [xsp+110h] [xbp-10h]

  v47 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 )
  {
    v42 = jiffies;
    if ( reg_get_pwrmode_chan_list___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 2u, "%s: invalid pdev", a4, a5, a6, a7, a8, a9, a10, a11, "reg_get_pwrmode_chan_list");
      reg_get_pwrmode_chan_list___last_ticks = v42;
      result = 4;
      goto LABEL_20;
    }
LABEL_17:
    result = 4;
    goto LABEL_20;
  }
  if ( !a2 )
  {
    v44 = jiffies;
    if ( reg_get_pwrmode_chan_list___last_ticks_11 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(0x51u, 2u, "%s: invalid chanlist", a4, a5, a6, a7, a8, a9, a10, a11, "reg_get_pwrmode_chan_list");
      reg_get_pwrmode_chan_list___last_ticks_11 = v44;
      result = 4;
      goto LABEL_20;
    }
    goto LABEL_17;
  }
  pdev_obj = (_BYTE *)reg_get_pdev_obj(a1);
  if ( !pdev_obj )
  {
    v45 = jiffies;
    if ( reg_get_pwrmode_chan_list___last_ticks_13 - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x51u,
        2u,
        "%s: reg pdev priv obj is NULL",
        v14,
        v15,
        v16,
        v17,
        v18,
        v19,
        v20,
        v21,
        "reg_get_pwrmode_chan_list");
      reg_get_pwrmode_chan_list___last_ticks_13 = v45;
      result = 4;
      goto LABEL_20;
    }
    goto LABEL_17;
  }
  v22 = pdev_obj;
  qdf_mem_copy(a2, pdev_obj, 0xE58u);
  if ( a3 )
  {
    if ( v22[11016] == 1 )
    {
      v31 = a2 + 770;
      v32 = v22 + 36940;
      v33 = -16080;
      do
      {
        memcpy(dest, &v32[v33 + 16080], sizeof(dest));
        v34 = dest[1];
        if ( a3 != -1 )
          v34 = a3;
        if ( v34 - 13 >= 0xFFFFFFF4 )
        {
          v35 = dest[v34 + 54];
          v36 = dest[v34 + 15];
          v37 = &dest[2 * v34 + 28];
          v38 = *((_WORD *)&dest[2] + v34);
          v39 = *((_WORD *)&dest[8] + v34 + 1);
          *((_DWORD *)v31 - 5) = v35;
          *((_DWORD *)v31 - 4) = v36;
          v40 = v37[1];
          *(v31 - 3) = v39;
          v41 = *((_WORD *)v37 + 1);
          *((_DWORD *)v31 - 3) = v40;
          LOBYTE(v40) = *(_BYTE *)v37;
          *(v31 - 4) = v38;
          *((_BYTE *)v31 - 1) = v40;
          *v31 = v41;
        }
        v33 += 268;
        v31 += 18;
      }
      while ( v33 );
    }
    else
    {
      qdf_trace_msg(
        0x51u,
        8u,
        "%s: 6G channel list is empty",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "reg_get_6g_pwrmode_chan_list");
    }
  }
  result = 0;
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
