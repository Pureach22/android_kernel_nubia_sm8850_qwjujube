__int64 __fastcall drv_cmd_get_wifi6e_channels(__int64 a1, __int64 a2, __int64 a3, unsigned __int8 a4, __int64 *a5)
{
  int v9; // w23
  unsigned int v10; // w0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x4
  const char *v20; // x2
  __int64 result; // x0
  char v22; // w8
  _WORD *v23; // x0
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  __int64 v32; // x19
  __int64 pwrmode_chan_list; // x0
  __int64 v34; // x1
  __int64 v35; // x2
  double v36; // d0
  double v37; // d1
  double v38; // d2
  double v39; // d3
  double v40; // d4
  double v41; // d5
  double v42; // d6
  double v43; // d7
  unsigned int v44; // w21
  unsigned int v45; // w20
  __int64 v46; // x22
  unsigned __int64 v47; // x23
  unsigned __int64 v48; // x25
  __int64 v49; // x8
  signed int v50; // w24
  _DWORD *v51; // x26
  int v52; // w8
  __int64 v53; // x20
  double v54; // d0
  double v55; // d1
  double v56; // d2
  double v57; // d3
  double v58; // d4
  double v59; // d5
  double v60; // d6
  double v61; // d7
  unsigned __int8 v62[4]; // [xsp+4h] [xbp-20Ch] BYREF
  _BYTE s[512]; // [xsp+8h] [xbp-208h] BYREF
  __int64 v64; // [xsp+208h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v62[0] = 0;
  memset(s, 0, sizeof(s));
  if ( *((int *)a5 + 3) >= 512 )
    v9 = 512;
  else
    v9 = *((_DWORD *)a5 + 3);
  if ( (unsigned int)_wlan_hdd_validate_context(a2, "drv_cmd_get_wifi6e_channels") )
    goto LABEL_8;
  v10 = kstrtou8(a3 + a4 + 1, 10, v62);
  if ( v10 )
  {
    v19 = v10;
    v20 = "%s: error %d parsing userspace 6 GHz power type parameter";
LABEL_7:
    qdf_trace_msg(0x33u, 2u, v20, v11, v12, v13, v14, v15, v16, v17, v18, "drv_cmd_get_wifi6e_channels", v19);
LABEL_8:
    result = 4294967274LL;
    goto LABEL_9;
  }
  v19 = v62[0];
  if ( v62[0] == 2 )
  {
    v22 = 5;
  }
  else if ( v62[0] == 1 )
  {
    v22 = 6;
  }
  else
  {
    if ( v62[0] )
    {
      v20 = "%s: The power type : %u, is incorrect";
      goto LABEL_7;
    }
    v22 = 4;
  }
  v62[0] = v22;
  v23 = (_WORD *)_qdf_mem_malloc(0xE58u, "drv_cmd_get_wifi6e_channels", 2757);
  if ( v23 )
  {
    v32 = (__int64)v23;
    pwrmode_chan_list = wlan_reg_get_pwrmode_chan_list(
                          *(_QWORD *)(a2 + 8),
                          v23,
                          v62[0],
                          v24,
                          v25,
                          v26,
                          v27,
                          v28,
                          v29,
                          v30,
                          v31);
    if ( (_DWORD)pwrmode_chan_list )
    {
      v44 = pwrmode_chan_list;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Failed to get wifi6e channel list for given power type %u",
        v36,
        v37,
        v38,
        v39,
        v40,
        v41,
        v42,
        v43,
        "drv_cmd_get_wifi6e_channels",
        v62[0]);
      v45 = qdf_status_to_os_return(v44);
    }
    else
    {
      v46 = v9;
      v47 = v9 - 1LL;
      if ( v47 )
      {
        v48 = 0;
        v49 = 0;
        v50 = 0;
        v51 = (_DWORD *)(v32 + 1520);
        do
        {
          if ( (*v51 & 0xFFFFFFFB) != 0 )
          {
            if ( (unsigned int)v50 >= 0x201 )
            {
              __break(0x5512u);
              return inline_copy_to_user(pwrmode_chan_list, v34, v35);
            }
            v36 = scnprintf(&s[v49], v46 - v49, "%u ", *((unsigned __int8 *)v51 - 4));
            v50 += pwrmode_chan_list;
          }
          if ( v48 > 0x3A )
            break;
          v49 = v50;
          ++v48;
          v51 += 9;
        }
        while ( v47 > v50 );
        if ( !v50 )
          goto LABEL_32;
        v52 = v50 + 1;
        if ( (unsigned int)(v50 + 1) >= 0x201 )
        {
          _copy_overflow(512, v52);
          goto LABEL_31;
        }
        v53 = *a5;
        _check_object_size(s, v52, 1);
        if ( inline_copy_to_user(v53, s, v50 + 1) )
        {
LABEL_31:
          qdf_trace_msg(
            0x33u,
            2u,
            "%s: failed to copy data to user buffer",
            v54,
            v55,
            v56,
            v57,
            v58,
            v59,
            v60,
            v61,
            "drv_cmd_get_wifi6e_channels");
          v45 = -14;
          goto LABEL_33;
        }
        qdf_trace_msg(
          0x33u,
          8u,
          "%s: Power type = %u, Data = %s",
          v54,
          v55,
          v56,
          v57,
          v58,
          v59,
          v60,
          v61,
          "drv_cmd_get_wifi6e_channels",
          v62[0],
          s);
        v45 = 0;
      }
      else
      {
LABEL_32:
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: No Channel List found for given power type %u",
          v36,
          v37,
          v38,
          v39,
          v40,
          v41,
          v42,
          v43,
          "drv_cmd_get_wifi6e_channels",
          v62[0]);
        v45 = -22;
      }
    }
LABEL_33:
    _qdf_mem_free(v32);
    result = v45;
  }
  else
  {
    result = 4294967284LL;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
