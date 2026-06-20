__int64 __fastcall wma_tbttoffset_update_event_handler(__int64 a1, _QWORD *a2)
{
  double v4; // d0
  double v5; // d1
  double v6; // d2
  double v7; // d3
  double v8; // d4
  double v9; // d5
  double v10; // d6
  double v11; // d7
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  __int64 v20; // x24
  unsigned int v21; // w8
  __int64 result; // x0
  unsigned int v23; // w25
  _QWORD *v24; // x26
  unsigned __int64 v25; // x21
  const char *v26; // x20
  unsigned __int64 StatusReg; // x28
  __int64 v28; // x27
  __int64 v29; // x8
  double v30; // d0
  double v31; // d1
  double v32; // d2
  double v33; // d3
  double v34; // d4
  double v35; // d5
  double v36; // d6
  double v37; // d7
  __int64 v38; // x27
  bool v39; // cc
  _DWORD s[154]; // [xsp+8h] [xbp-278h] BYREF
  __int64 v41; // [xsp+270h] [xbp-10h]

  v41 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(s, 0, sizeof(s));
  if ( (unsigned int)_wma_validate_handle(
                       a1,
                       (__int64)"wma_tbttoffset_update_event_handler",
                       v4,
                       v5,
                       v6,
                       v7,
                       v8,
                       v9,
                       v10,
                       v11) )
    goto LABEL_28;
  if ( !a2 )
  {
    v26 = "%s: Invalid tbtt update event buffer";
    goto LABEL_27;
  }
  v20 = a2[2];
  if ( !v20 )
  {
    v26 = "%s: Invalid adjusted_tsf";
    goto LABEL_27;
  }
  v21 = *(unsigned __int16 *)(a1 + 162);
  result = 0;
  if ( *(_WORD *)(a1 + 162) )
  {
    v23 = *(_DWORD *)(*a2 + 4LL);
    if ( v23 )
    {
      v24 = *(_QWORD **)(a1 + 520);
      v25 = 0;
      v26 = "%s: Invalid beacon";
      StatusReg = _ReadStatusReg(SP_EL0);
      while ( 1 )
      {
        if ( *v24 && (v23 & 1) != 0 )
        {
          v28 = v24[1];
          if ( !v28 )
            goto LABEL_27;
          if ( !*(_QWORD *)v28 )
          {
            v26 = "%s: Invalid beacon buffer";
LABEL_27:
            qdf_trace_msg(0x36u, 2u, v26, v12, v13, v14, v15, v16, v17, v18, v19, "wma_tbttoffset_update_event_handler");
LABEL_28:
            result = 4294967274LL;
            break;
          }
          v24[24] = *(unsigned int *)(v20 + 4 * v25);
          if ( (_ReadStatusReg(DAIF) & 0x80) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0
            || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
          {
            raw_spin_lock(v28 + 104);
          }
          else
          {
            raw_spin_lock_bh(v28 + 104);
            *(_QWORD *)(v28 + 112) |= 1uLL;
          }
          qdf_mem_set(s, 0x268u, 0);
          qdf_mem_copy((char *)&s[1] + 3, *(const void **)(*(_QWORD *)v28 + 224LL), *(unsigned int *)(v28 + 8));
          LOWORD(s[132]) = *(_WORD *)(v28 + 96);
          s[130] = *(_DWORD *)(v28 + 8);
          s[131] = *(_DWORD *)(v28 + 16);
          s[133] = *(unsigned __int16 *)(v28 + 98);
          s[134] = *(unsigned __int16 *)(v28 + 100);
          v29 = *(_QWORD *)(v28 + 112);
          if ( (v29 & 1) != 0 )
          {
            *(_QWORD *)(v28 + 112) = v29 & 0xFFFFFFFFFFFFFFFELL;
            raw_spin_unlock_bh(v28 + 104);
          }
          else
          {
            raw_spin_unlock(v28 + 104);
          }
          v38 = jiffies;
          if ( wma_tbttoffset_update_event_handler___last_ticks - jiffies + 125 < 0 )
          {
            qdf_trace_msg(
              0x36u,
              2u,
              "%s: Update beacon template for vdev %d due to TBTT offset update",
              v30,
              v31,
              v32,
              v33,
              v34,
              v35,
              v36,
              v37,
              "wma_tbttoffset_update_event_handler",
              (unsigned int)v25);
            wma_tbttoffset_update_event_handler___last_ticks = v38;
          }
          wma_unified_bcn_tmpl_send(a1, (unsigned int)v25, s, 0);
          v21 = *(unsigned __int16 *)(a1 + 162);
        }
        ++v25;
        result = 0;
        if ( v25 < v21 )
        {
          v39 = v23 > 1;
          v24 += 61;
          v23 >>= 1;
          if ( v39 )
            continue;
        }
        break;
      }
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
