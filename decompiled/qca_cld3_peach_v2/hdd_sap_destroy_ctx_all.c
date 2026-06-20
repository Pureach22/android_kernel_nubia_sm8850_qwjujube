__int64 __fastcall hdd_sap_destroy_ctx_all(
        __int64 result,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x19
  unsigned __int64 StatusReg; // x8
  __int64 v12; // x1
  __int64 v13; // x8
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  __int64 v22; // x20
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x23
  __int64 v26; // x8
  __int64 v27; // x9
  __int64 v28; // x10
  unsigned __int64 v29; // [xsp+0h] [xbp-20h]
  __int64 v30; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v31[2]; // [xsp+10h] [xbp-10h] BYREF

  v31[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v30 = 0;
  if ( (a2 & 1) == 0 )
  {
    v10 = result;
    v31[0] = 0;
    qdf_trace_msg(
      0x33u,
      8u,
      "%s: destroying all the sap context",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "hdd_sap_destroy_ctx_all");
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(v10 + 32);
    }
    else
    {
      raw_spin_lock_bh(v10 + 32);
      *(_QWORD *)(v10 + 40) |= 1uLL;
    }
    hdd_get_front_adapter_no_lock(v10, v31);
    if ( v31[0] )
    {
      hdd_adapter_dev_hold_debug(v31[0], 6);
      v12 = v31[0];
    }
    else
    {
      v12 = 0;
    }
    hdd_get_next_adapter_no_lock(v10, v12, &v30);
    if ( v30 )
      hdd_adapter_dev_hold_debug(v30, 6);
    v13 = *(_QWORD *)(v10 + 40);
    if ( (v13 & 1) != 0 )
    {
      *(_QWORD *)(v10 + 40) = v13 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 32);
      result = v31[0];
      if ( !v31[0] )
        goto LABEL_47;
    }
    else
    {
      raw_spin_unlock(v10 + 32);
      result = v31[0];
      if ( !v31[0] )
        goto LABEL_47;
    }
    v29 = _ReadStatusReg(SP_EL0);
    do
    {
      while ( 1 )
      {
        if ( *(_DWORD *)(result + 40) == 1 )
        {
          if ( (*(_QWORD *)(result + 1640) & 1) != 0 && (v22 = result + 52840, result != -52840)
            || (*(_QWORD *)(result + 1640) & 2) != 0 && (v22 = result + 58928, result != -58928)
            || (*(_QWORD *)(result + 1640) & 4) != 0 && (v22 = result + 65016, result != -65016) )
          {
            do
            {
              v24 = *(_QWORD *)(v22 + 2432);
              v25 = *(_QWORD *)(v22 + 272);
              if ( v24 )
              {
                _qdf_mem_free(v24);
                *(_QWORD *)(v22 + 2432) = 0;
              }
              if ( v25 )
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: destroying sap context",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hdd_sap_destroy_ctx");
                if ( !(unsigned int)sap_destroy_ctx(v25) )
                  *(_QWORD *)(v22 + 272) = 0;
              }
              else
              {
                qdf_trace_msg(
                  0x33u,
                  8u,
                  "%s: sap context is NULL",
                  v14,
                  v15,
                  v16,
                  v17,
                  v18,
                  v19,
                  v20,
                  v21,
                  "hdd_sap_destroy_ctx");
              }
              result = v31[0];
              if ( v31[0] )
              {
                if ( (unsigned __int8)(73 * ((unsigned int)(v22 - *(_DWORD *)v22 - 52840) >> 3) + 1) > 2u )
                  break;
                v26 = (unsigned __int8)(73 * ((unsigned int)(v22 - *(_DWORD *)v22 - 52840) >> 3) + 1);
                v22 = 0;
                v27 = v31[0] + 6088LL * (unsigned int)v26 + 52840;
                do
                {
                  if ( v22 )
                    break;
                  v28 = *(_QWORD *)(v31[0] + 1640LL) >> v26++;
                  v22 = (v28 << 63 >> 63) & v27;
                  v27 += 6088;
                }
                while ( v26 != 3 );
              }
            }
            while ( v22 );
          }
        }
        hdd_adapter_dev_put_debug(result, 6);
        if ( (_ReadStatusReg(DAIF) & 0x80) != 0
          || (*(_DWORD *)(v29 + 16) & 0xF0000) != 0
          || (*(_DWORD *)(v29 + 16) & 0xFF00) != 0 )
        {
          raw_spin_lock(v10 + 32);
        }
        else
        {
          raw_spin_lock_bh(v10 + 32);
          *(_QWORD *)(v10 + 40) |= 1uLL;
        }
        v31[0] = v30;
        hdd_get_next_adapter_no_lock(v10, v30, &v30);
        hdd_validate_next_adapter(v31, &v30, 6);
        if ( v30 )
          hdd_adapter_dev_hold_debug(v30, 6);
        v23 = *(_QWORD *)(v10 + 40);
        if ( (v23 & 1) != 0 )
          break;
        raw_spin_unlock(v10 + 32);
        result = v31[0];
        if ( !v31[0] )
          goto LABEL_47;
      }
      *(_QWORD *)(v10 + 40) = v23 & 0xFFFFFFFFFFFFFFFELL;
      raw_spin_unlock_bh(v10 + 32);
      result = v31[0];
    }
    while ( v31[0] );
  }
LABEL_47:
  _ReadStatusReg(SP_EL0);
  return result;
}
