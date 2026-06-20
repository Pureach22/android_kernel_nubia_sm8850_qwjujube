__int64 __fastcall lim_set_tpc_power(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v16; // x0
  double v17; // d0
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  __int64 result; // x0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  __int64 v34; // x24
  double v35; // d0
  double v36; // d1
  double v37; // d2
  double v38; // d3
  double v39; // d4
  double v40; // d5
  double v41; // d6
  double v42; // d7
  int v43; // w8
  __int64 v44; // x22
  void (__fastcall *v45)(__int64, __int64, __int64); // x8
  __int64 v46; // x0
  __int64 v47; // x1
  _BYTE v48[4]; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v49; // [xsp+8h] [xbp-8h]

  v49 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v16 = *(_QWORD *)(a1 + 21552);
  v48[0] = 0;
  if ( (wlan_reg_is_ext_tpc_supported(v16, a5, a6, a7, a8, a9, a10, a11, a12) & 1) == 0 )
  {
LABEL_17:
    result = 1;
    goto LABEL_18;
  }
  result = wlan_reg_get_tx_ops(*(_QWORD *)(a1 + 21552), v17, v18, v19, v20, v21, v22, v23, v24);
  if ( result )
  {
    if ( *(_QWORD *)(result + 144) )
    {
      v34 = result;
      result = wlan_vdev_mlme_get_cmpt_obj(*(_QWORD *)(a2 + 16), v26, v27, v28, v29, v30, v31, v32, v33);
      if ( result )
      {
        v43 = *(_DWORD *)(a2 + 7036);
        v44 = result;
        if ( v43 )
        {
          if ( !a3 || v43 != 2 )
          {
LABEL_12:
            if ( (v43 | 2) == 3 )
              *(_BYTE *)(v44 + 533) = 0;
            goto LABEL_14;
          }
        }
        else if ( !a3 )
        {
LABEL_14:
          lim_calculate_tpc(a1, a2, a4 & 1, v35, v36, v37, v38, v39, v40, v41, v42);
          v45 = *(void (__fastcall **)(__int64, __int64, __int64))(v34 + 144);
          v46 = *(_QWORD *)(a1 + 21552);
          v47 = *(unsigned __int8 *)(a2 + 10);
          if ( *((_DWORD *)v45 - 1) != 1094041931 )
            __break(0x8228u);
          v45(v46, v47, v44 + 528);
          goto LABEL_17;
        }
        lim_process_tpe_ie_from_beacon(a1, a2, a3, v48);
        v43 = *(_DWORD *)(a2 + 7036);
        goto LABEL_12;
      }
    }
    else
    {
      result = 0;
    }
  }
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
