__int64 __fastcall sap_chan_bond_dfs_sub_chan(
        _DWORD *a1,
        unsigned int a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  _QWORD *context; // x0
  double v15; // d0
  double v16; // d1
  double v17; // d2
  double v18; // d3
  double v19; // d4
  double v20; // d5
  double v21; // d6
  double v22; // d7
  __int64 v23; // x20
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  int v32; // w8
  unsigned int v33; // w23
  unsigned int v34; // w26
  char v35; // w24
  unsigned int v36; // w25
  unsigned int v37; // w22
  unsigned int v38; // w9
  unsigned int v39; // w10
  unsigned int v40; // w11
  unsigned int v41; // w12
  char v42; // w27
  char v43; // w28
  const char *v44; // x2
  bool v46; // zf
  int v47; // w8
  int v48; // w8
  unsigned int v49; // w21
  double v50; // d0
  double v51; // d1
  double v52; // d2
  double v53; // d3
  double v54; // d4
  double v55; // d5
  double v56; // d6
  double v57; // d7
  unsigned int v58; // [xsp+4h] [xbp-Ch]
  unsigned int v59; // [xsp+8h] [xbp-8h]
  unsigned int v60; // [xsp+Ch] [xbp-4h]

  context = _cds_get_context(53, (__int64)"sap_get_mac_context", a4, a5, a6, a7, a8, a9, a10, a11);
  if ( !context )
  {
    v44 = "%s: Invalid MAC context";
LABEL_12:
    qdf_trace_msg(0x39u, 2u, v44, v15, v16, v17, v18, v19, v20, v21, v22, "sap_chan_bond_dfs_sub_chan");
    return 0;
  }
  v23 = context[2704];
  if ( !v23 )
  {
    v44 = "%s: null pdev";
    goto LABEL_12;
  }
  if ( (wlan_reg_chan_has_dfs_attribute_for_freq(context[2704], a2, v15, v16, v17, v18, v19, v20, v21, v22) & 1) == 0 )
  {
    if ( (unsigned int)a3 >= 0xB && *a1 == a2 )
    {
      v32 = a1[375];
      v33 = a1[377];
      v34 = 0;
      v35 = 1;
      if ( v32 > 2 )
      {
        if ( v32 == 4 )
        {
          v48 = a1[378];
          v35 = 0;
          v42 = 0;
          v43 = 0;
          v34 = v33 - 10;
          v36 = v33 + 10;
          v37 = v33 + 30;
          v33 -= 30;
          v38 = v48 - 30;
          v39 = v48 - 10;
          v40 = v48 + 10;
          v41 = v48 + 30;
        }
        else
        {
          v36 = 0;
          v37 = 0;
          v38 = 0;
          v39 = 0;
          v40 = 0;
          v41 = 0;
          v42 = 0;
          v43 = 0;
          if ( v32 == 3 )
          {
            v47 = a1[378];
            v35 = 0;
            v42 = 0;
            v43 = 0;
            v33 = v47 - 70;
            v34 = v47 - 50;
            v36 = v47 - 30;
            v37 = v47 - 10;
            v38 = v47 + 10;
            v39 = v47 + 30;
            v40 = v47 + 50;
            v41 = v47 + 70;
          }
        }
      }
      else if ( v32 == 1 )
      {
        v36 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v35 = 0;
        v43 = 0;
        v34 = v33 + 10;
        v42 = 1;
        v33 -= 10;
      }
      else
      {
        v36 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v42 = 0;
        v43 = 0;
        if ( v32 == 2 )
        {
          v38 = 0;
          v39 = 0;
          v40 = 0;
          v41 = 0;
          v35 = 0;
          v42 = 0;
          v34 = v33 - 10;
          v36 = v33 + 10;
          v37 = v33 + 30;
          v43 = 1;
          v33 -= 30;
        }
      }
    }
    else
    {
      v34 = 0;
      v35 = 1;
      if ( a3 > 7 )
      {
        if ( a3 == 8 )
        {
          v38 = 0;
          v39 = 0;
          v40 = 0;
          v41 = 0;
          v35 = 0;
          v42 = 0;
          v33 = a2 - 20;
          v36 = a2 + 20;
          v37 = a2 + 40;
          v43 = 1;
          v34 = a2;
        }
        else if ( a3 == 9 )
        {
          v38 = 0;
          v39 = 0;
          v40 = 0;
          v41 = 0;
          v35 = 0;
          v42 = 0;
          v33 = a2 - 40;
          v34 = a2 - 20;
          v37 = a2 + 20;
          v43 = 1;
          v36 = a2;
        }
        else
        {
          v46 = a3 == 10;
          v33 = a2;
          v36 = 0;
          v37 = 0;
          v38 = 0;
          v39 = 0;
          v40 = 0;
          v41 = 0;
          v42 = 0;
          v43 = 0;
          if ( v46 )
          {
            v38 = 0;
            v39 = 0;
            v40 = 0;
            v41 = 0;
            v35 = 0;
            v42 = 0;
            v33 = a2 - 60;
            v34 = a2 - 40;
            v36 = a2 - 20;
            v43 = 1;
            v37 = a2;
          }
        }
      }
      else if ( a3 == 1 )
      {
        v36 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v35 = 0;
        v43 = 0;
        v34 = a2 + 20;
        v42 = 1;
        v33 = a2;
      }
      else if ( a3 == 3 )
      {
        v36 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v35 = 0;
        v43 = 0;
        v33 = a2 - 20;
        v42 = 1;
        v34 = a2;
      }
      else
      {
        v46 = a3 == 7;
        v33 = a2;
        v36 = 0;
        v37 = 0;
        v38 = 0;
        v39 = 0;
        v40 = 0;
        v41 = 0;
        v42 = 0;
        v43 = 0;
        if ( v46 )
        {
          v38 = 0;
          v39 = 0;
          v40 = 0;
          v41 = 0;
          v35 = 0;
          v42 = 0;
          v34 = a2 + 20;
          v36 = a2 + 40;
          v37 = a2 + 60;
          v43 = 1;
          v33 = a2;
        }
      }
    }
    v60 = v39;
    v58 = v41;
    v59 = v40;
    v49 = v38;
    if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v33, v24, v25, v26, v27, v28, v29, v30, v31) & 1) == 0 )
    {
      if ( (v35 & 1) != 0 )
        return 0;
      v33 = v34;
      if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v34, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
      {
        if ( (v42 & 1) != 0 )
          return 0;
        v33 = v36;
        if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v36, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
        {
          v33 = v37;
          if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v37, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
          {
            if ( (v43 & 1) != 0 )
              return 0;
            v33 = v49;
            if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v49, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
            {
              v33 = v60;
              if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v60, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
              {
                v33 = v59;
                if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v59, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
                {
                  v33 = v58;
                  if ( (wlan_reg_chan_has_dfs_attribute_for_freq(v23, v58, v50, v51, v52, v53, v54, v55, v56, v57) & 1) == 0 )
                    return 0;
                }
              }
            }
          }
        }
      }
    }
    qdf_trace_msg(
      0x39u,
      8u,
      "%s: sub ch freq=%d is dfs in %d",
      v50,
      v51,
      v52,
      v53,
      v54,
      v55,
      v56,
      v57,
      "sap_chan_bond_dfs_sub_chan",
      v33,
      a2);
  }
  return 1;
}
