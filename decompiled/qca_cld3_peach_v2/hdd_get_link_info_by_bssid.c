__int64 __fastcall hdd_get_link_info_by_bssid(__int64 a1, int *a2)
{
  int v2; // w8
  int v3; // w9
  unsigned __int64 StatusReg; // x8
  unsigned int *v7; // x8
  double v8; // d0
  double v9; // d1
  double v10; // d2
  double v11; // d3
  double v12; // d4
  double v13; // d5
  double v14; // d6
  double v15; // d7
  __int64 v16; // x1
  __int64 result; // x0
  unsigned int *v18; // x8
  double v19; // d0
  double v20; // d1
  double v21; // d2
  double v22; // d3
  double v23; // d4
  double v24; // d5
  double v25; // d6
  double v26; // d7
  __int64 v27; // x8
  double v28; // d0
  double v29; // d1
  double v30; // d2
  double v31; // d3
  double v32; // d4
  double v33; // d5
  double v34; // d6
  double v35; // d7
  unsigned __int64 v36; // x22
  __int64 v37; // x8
  __int64 v38; // x9
  double v40; // d0
  double v41; // d1
  double v42; // d2
  double v43; // d3
  double v44; // d4
  double v45; // d5
  double v46; // d6
  double v47; // d7
  unsigned int *v48; // x8
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  __int64 v57; // x8
  __int64 v58; // x19
  double v59; // d0
  double v60; // d1
  double v61; // d2
  double v62; // d3
  double v63; // d4
  double v64; // d5
  double v65; // d6
  double v66; // d7
  __int64 v67; // [xsp+0h] [xbp-20h] BYREF
  __int64 v68[3]; // [xsp+8h] [xbp-18h] BYREF

  v68[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *a2;
  v3 = *((unsigned __int16 *)a2 + 2);
  v67 = 0;
  v68[0] = 0;
  if ( v2 | v3 )
  {
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 32);
    }
    else
    {
      raw_spin_lock_bh(a1 + 32);
      *(_QWORD *)(a1 + 40) |= 1uLL;
    }
    hdd_get_front_adapter_no_lock(a1, v68);
    if ( v68[0] )
    {
      hdd_adapter_dev_hold_debug(v68[0], 0x3Eu, v7, v8, v9, v10, v11, v12, v13, v14, v15);
      v16 = v68[0];
    }
    else
    {
      v16 = 0;
    }
    hdd_get_next_adapter_no_lock(a1, v16, &v67);
    if ( v67 )
      hdd_adapter_dev_hold_debug(v67, 0x3Eu, v18, v19, v20, v21, v22, v23, v24, v25, v26);
    v27 = *(_QWORD *)(a1 + 40);
    if ( (v27 & 1) != 0 )
    {
      *(_QWORD *)(a1 + 40) = v27 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      result = v68[0];
      if ( !v68[0] )
        goto LABEL_38;
    }
    else
    {
      raw_spin_unlock(a1 + 32);
      result = v68[0];
      if ( !v68[0] )
        goto LABEL_38;
    }
    v36 = _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
        v37 = result + 52840;
        if ( result != -52840 )
        {
          v38 = 0;
          while ( (unsigned __int64)(0x71B3F945A27B1F49LL * (v38 >> 3)) <= 2 )
          {
            if ( *a2 == *(_DWORD *)(v37 + 308) && *((unsigned __int16 *)a2 + 2) == *(unsigned __int16 *)(v37 + 312) )
            {
              v58 = v37;
              hdd_adapter_dev_put_debug(result, 0x3Eu, v28, v29, v30, v31, v32, v33, v34, v35);
              if ( v67 )
                hdd_adapter_dev_put_debug(v67, 0x3Eu, v59, v60, v61, v62, v63, v64, v65, v66);
              result = v58;
              goto LABEL_38;
            }
            v37 += 6088;
            v38 += 6088;
            if ( !v37 )
              break;
          }
        }
        hdd_adapter_dev_put_debug(result, 0x3Eu, v28, v29, v30, v31, v32, v33, v34, v35);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v36 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v36 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(a1 + 32);
        }
        else
        {
          raw_spin_lock_bh(a1 + 32);
          *(_QWORD *)(a1 + 40) |= 1uLL;
        }
        v68[0] = v67;
        hdd_get_next_adapter_no_lock(a1, v67, &v67);
        hdd_validate_next_adapter(v68, &v67, 0x3Eu, v40, v41, v42, v43, v44, v45, v46, v47);
        if ( v67 )
          hdd_adapter_dev_hold_debug(v67, 0x3Eu, v48, v49, v50, v51, v52, v53, v54, v55, v56);
        v57 = *(_QWORD *)(a1 + 40);
        if ( (v57 & 1) != 0 )
          break;
        raw_spin_unlock(a1 + 32);
        result = v68[0];
        if ( !v68[0] )
          goto LABEL_38;
      }
      *(_QWORD *)(a1 + 40) = v57 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(a1 + 32);
      result = v68[0];
    }
    while ( v68[0] );
  }
  else
  {
    result = 0;
  }
LABEL_38:
  _ReadStatusReg(SP_EL0);
  return result;
}
