__int64 __fastcall hdd_set_phy_mode(
        __int64 a1,
        unsigned int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 *v10; // x19
  __int64 v11; // x21
  unsigned int v12; // w22
  __int64 result; // x0
  double v15; // d0
  unsigned int v16; // w0
  unsigned int v17; // w23
  double v18; // d1
  double v19; // d2
  double v20; // d3
  double v21; // d4
  double v22; // d5
  double v23; // d6
  double v24; // d7
  unsigned int max_phymode; // w0
  double v26; // d0
  double v27; // d1
  double v28; // d2
  double v29; // d3
  double v30; // d4
  double v31; // d5
  double v32; // d6
  double v33; // d7
  unsigned int v34; // w23
  unsigned int v35; // w22
  __int64 v36; // x0
  char is_6ghz_supported; // w0
  unsigned __int64 StatusReg; // x8
  __int64 v39; // x1
  __int64 v40; // x8
  __int64 v41; // x8
  unsigned __int64 v42; // x21
  char is_vdev_connected; // w0
  __int64 v44; // x8
  __int64 v45; // [xsp+8h] [xbp-28h] BYREF
  __int64 v46; // [xsp+10h] [xbp-20h] BYREF
  unsigned int v47; // [xsp+18h] [xbp-18h] BYREF
  _BYTE v48[4]; // [xsp+1Ch] [xbp-14h] BYREF
  unsigned int v49; // [xsp+20h] [xbp-10h] BYREF
  unsigned int v50; // [xsp+24h] [xbp-Ch] BYREF
  __int64 v51; // [xsp+28h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = *(__int64 **)(a1 + 24);
  v49 = a2;
  v50 = 0;
  v48[0] = 0;
  v11 = *v10;
  v47 = 0;
  v45 = 0;
  v46 = 0;
  if ( !v11 )
  {
    qdf_trace_msg(0x33u, 2u, "%s: psoc is NULL", a3, a4, a5, a6, a7, a8, a9, a10, "hdd_set_phy_mode");
    result = 4294967274LL;
    goto LABEL_11;
  }
  v12 = a2;
  result = hdd_vendor_mode_to_phymode(a2, &v50);
  if ( (result & 0x80000000) == 0 )
  {
    v15 = csr_convert_to_reg_phy_mode(v50, 0);
    v17 = v16;
    max_phymode = wlan_reg_get_max_phymode(v10[1], v16, 0, v15, v18, v19, v20, v21, v22, v23, v24);
    if ( v17 == max_phymode )
    {
      v34 = v50;
      v49 = v12;
    }
    else
    {
      v35 = max_phymode;
      qdf_trace_msg(
        0x33u,
        8u,
        "%s: reg_max_phymode %d, req_req_phymode %d",
        v26,
        v27,
        v28,
        v29,
        v30,
        v31,
        v32,
        v33,
        "hdd_set_phy_mode",
        max_phymode,
        v17);
      v36 = csr_convert_from_reg_phy_mode(v35);
      v34 = v36;
      result = hdd_phymode_to_vendor_mode(v36, &v49);
      if ( (_DWORD)result )
        goto LABEL_11;
      v12 = v49;
    }
    is_6ghz_supported = wlan_reg_is_6ghz_supported(v11, v26, v27, v28, v29, v30, v31, v32, v33);
    result = hdd_vendor_mode_to_band(v12, v48, is_6ghz_supported & 1);
    if ( (result & 0x80000000) == 0 )
    {
      result = hdd_vendor_mode_to_bonding_mode(v49, &v47);
      if ( (result & 0x80000000) == 0 )
      {
        result = hdd_update_phymode(a1, v34, v48[0], v47);
        if ( !(_DWORD)result )
        {
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v10 + 4);
          }
          else
          {
            raw_spin_lock_bh(v10 + 4);
            v10[5] |= 1uLL;
          }
          hdd_get_front_adapter_no_lock(v10, &v46);
          if ( v46 )
          {
            hdd_adapter_dev_hold_debug(v46, 22);
            v39 = v46;
          }
          else
          {
            v39 = 0;
          }
          hdd_get_next_adapter_no_lock(v10, v39, &v45);
          if ( v45 )
            hdd_adapter_dev_hold_debug(v45, 22);
          v40 = v10[5];
          if ( (v40 & 1) != 0 )
          {
            v10[5] = v40 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v10 + 4);
            v41 = v46;
            if ( v46 )
            {
LABEL_23:
              v42 = _ReadStatusReg(SP_EL0);
              do
              {
                if ( !*(_DWORD *)(v41 + 40) )
                {
                  is_vdev_connected = hdd_cm_is_vdev_connected(*(_QWORD *)(v41 + 52832));
                  v41 = v46;
                  if ( (is_vdev_connected & 1) == 0 )
                  {
                    hdd_set_vdev_phy_mode(v46, v49);
                    v41 = v46;
                  }
                }
                hdd_adapter_dev_put_debug(v41, 22);
                if ( (_ReadStatusReg(DAIF) & 0x80) != 0
                  || (*(_DWORD *)(v42 + 16) & 0xF0000) != 0
                  || (*(_DWORD *)(v42 + 16) & 0xFF00) != 0 )
                {
                  raw_spin_lock(v10 + 4);
                }
                else
                {
                  raw_spin_lock_bh(v10 + 4);
                  v10[5] |= 1uLL;
                }
                v46 = v45;
                hdd_get_next_adapter_no_lock(v10, v45, &v45);
                hdd_validate_next_adapter(&v46, &v45, 22);
                if ( v45 )
                  hdd_adapter_dev_hold_debug(v45, 22);
                v44 = v10[5];
                if ( (v44 & 1) != 0 )
                {
                  v10[5] = v44 & 0xFFFFFFFFFFFFFFFELL;
                  raw_spin_unlock_bh(v10 + 4);
                }
                else
                {
                  raw_spin_unlock(v10 + 4);
                }
                v41 = v46;
                result = 0;
              }
              while ( v46 );
              goto LABEL_11;
            }
          }
          else
          {
            raw_spin_unlock(v10 + 4);
            v41 = v46;
            if ( v46 )
              goto LABEL_23;
          }
          result = 0;
        }
      }
    }
  }
LABEL_11:
  _ReadStatusReg(SP_EL0);
  return result;
}
