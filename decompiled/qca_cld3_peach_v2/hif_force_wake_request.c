__int64 __fastcall hif_force_wake_request(__int64 a1)
{
  double v2; // d0
  double v3; // d1
  double v4; // d2
  double v5; // d3
  double v6; // d4
  double v7; // d5
  double v8; // d6
  double v9; // d7
  __int64 result; // x0
  unsigned __int64 StatusReg; // x23
  unsigned int v12; // w20
  unsigned int v13; // w0
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  unsigned int v22; // w20
  unsigned int v23; // w19
  double v24; // d0
  double v25; // d1
  double v26; // d2
  double v27; // d3
  double v28; // d4
  double v29; // d5
  double v30; // d6
  double v31; // d7
  double v32; // d0
  double v33; // d1
  double v34; // d2
  double v35; // d3
  double v36; // d4
  double v37; // d5
  double v38; // d6
  double v39; // d7
  __int64 v40; // x8
  unsigned int v47; // w8
  signed int v48; // w8
  __int64 v49; // x9
  unsigned int v50; // w0
  unsigned int v51; // w20
  double v52; // d0
  double v53; // d1
  double v54; // d2
  double v55; // d3
  double v56; // d4
  double v57; // d5
  double v58; // d6
  double v59; // d7
  double v60; // d0
  double v61; // d1
  double v62; // d2
  double v63; // d3
  double v64; // d4
  double v65; // d5
  double v66; // d6
  double v67; // d7
  unsigned int v68; // w0
  double v69; // d0
  double v70; // d1
  double v71; // d2
  double v72; // d3
  double v73; // d4
  double v74; // d5
  double v75; // d6
  double v76; // d7
  unsigned int v79; // w10
  __int64 v80; // x8

  if ( (unsigned int)hif_rtpm_get(2u, 7u) )
  {
    qdf_trace_msg(0x3Du, 2u, "%s: runtime pm get failed", v2, v3, v4, v5, v6, v7, v8, v9, "hif_force_wake_request");
    return 4294967274LL;
  }
  StatusReg = _ReadStatusReg(SP_EL0);
  ++*(_DWORD *)(a1 + 31208);
  if ( (*(_DWORD *)(StatusReg + 16) & 0xFFFF00) != 0 )
    v12 = 50000;
  else
    v12 = 0;
  v13 = pld_force_wake_request_sync(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL), v12);
  if ( !v13 )
  {
    if ( !(unsigned int)pld_is_device_awake(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL)) )
      qdf_trace_msg(
        0x3Du,
        5u,
        "%s: state-change event races, ignore",
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        v39,
        "hif_force_wake_request");
    ++*(_DWORD *)(a1 + 31216);
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      raw_spin_lock(a1 + 31264);
    }
    else
    {
      raw_spin_lock_bh(a1 + 31264);
      *(_QWORD *)(a1 + 31272) |= 1uLL;
    }
    _X9 = (unsigned int *)(a1 + 696);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v47 = __ldxr(_X9);
      v48 = v47 + 1;
    }
    while ( __stlxr(v48, _X9) );
    __dmb(0xBu);
    if ( v48 >= 2 )
    {
      v40 = *(_QWORD *)(a1 + 31272);
      if ( (v40 & 1) != 0 )
        goto LABEL_35;
    }
    else
    {
      hif_write32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 12292, 1u);
      v49 = *(_QWORD *)(a1 + 40);
      ++*(_DWORD *)(a1 + 31220);
      if ( (unsigned int)hif_read32_mb_reg_window(a1, v49 + 31473728) != 2 )
      {
        _const_udelay(21475000);
        if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
        {
          _const_udelay(21475000);
          if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
          {
            _const_udelay(21475000);
            if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
            {
              _const_udelay(21475000);
              if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
              {
                _const_udelay(21475000);
                if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
                {
                  _const_udelay(21475000);
                  if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
                  {
                    _const_udelay(21475000);
                    if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
                    {
                      _const_udelay(21475000);
                      if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
                      {
                        _const_udelay(21475000);
                        if ( (unsigned int)hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL) != 2 )
                        {
                          _const_udelay(21475000);
                          v50 = hif_read32_mb_reg_window(a1, *(_QWORD *)(a1 + 40) + 31473728LL);
                          if ( v50 != 2 )
                          {
                            v51 = v50;
                            _const_udelay(21475000);
                            qdf_trace_msg(
                              0x3Du,
                              2u,
                              "%s: force wake handshake failed, reg value = 0x%x",
                              v52,
                              v53,
                              v54,
                              v55,
                              v56,
                              v57,
                              v58,
                              v59,
                              "hif_soc_wake_request",
                              v51);
                            ++*(_DWORD *)(a1 + 31224);
                            _X8 = (unsigned int *)(a1 + 696);
                            __asm { PRFM            #0x11, [X8] }
                            do
                              v79 = __ldxr(_X8);
                            while ( __stxr(v79 - 1, _X8) );
                            v80 = *(_QWORD *)(a1 + 31272);
                            if ( (v80 & 1) != 0 )
                            {
                              *(_QWORD *)(a1 + 31272) = v80 & 0xFFFFFFFFFFFFFFFELL;
                              raw_spin_unlock_bh(a1 + 31264);
                            }
                            else
                            {
                              raw_spin_unlock(a1 + 31264);
                            }
                            qdf_trace_msg(
                              0x3Du,
                              2u,
                              "%s: soc force wake failed: %d",
                              v60,
                              v61,
                              v62,
                              v63,
                              v64,
                              v65,
                              v66,
                              v67,
                              "hif_force_wake_request",
                              4294967186LL);
                            v68 = pld_force_wake_release(*(_QWORD *)(*(_QWORD *)(a1 + 576) + 40LL));
                            if ( v68 )
                            {
                              v22 = v68;
                              qdf_trace_msg(
                                0x3Du,
                                2u,
                                "%s: pld force wake release failure",
                                v69,
                                v70,
                                v71,
                                v72,
                                v73,
                                v74,
                                v75,
                                v76,
                                "hif_force_wake_request");
                              ++*(_DWORD *)(a1 + 31232);
                            }
                            else
                            {
                              v22 = -110;
                              ++*(_DWORD *)(a1 + 31236);
                            }
                            goto LABEL_9;
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
      v40 = *(_QWORD *)(a1 + 31272);
      ++*(_DWORD *)(a1 + 31228);
      if ( (v40 & 1) != 0 )
      {
LABEL_35:
        *(_QWORD *)(a1 + 31272) = v40 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(a1 + 31264);
        return 0;
      }
    }
    raw_spin_unlock(a1 + 31264);
    return 0;
  }
  qdf_trace_msg(
    0x3Du,
    2u,
    "%s: force wake request(timeout %u) send failed: %d",
    v14,
    v15,
    v16,
    v17,
    v18,
    v19,
    v20,
    v21,
    "hif_force_wake_request",
    v12,
    v13);
  v22 = -22;
  ++*(_DWORD *)(a1 + 31212);
LABEL_9:
  v23 = hif_rtpm_put(4, 7u);
  result = v22;
  if ( v23 )
  {
    qdf_trace_msg(
      0x3Du,
      2u,
      "%s: runtime pm put failure: %d",
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      v30,
      v31,
      "hif_force_wake_request",
      v23);
    return v23;
  }
  return result;
}
