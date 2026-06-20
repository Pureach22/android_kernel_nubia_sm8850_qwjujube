__int64 __fastcall hdd_put_sta_info_ref(
        __int64 result,
        __int64 *a2,
        char a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  __int64 v12; // x19
  const char *v13; // x2
  unsigned int v14; // w20
  __int64 *v15; // x21
  char v16; // w22
  unsigned __int64 StatusReg; // x8
  __int64 v18; // x23
  __int64 v19; // x20
  __int64 *v20; // x21
  char v21; // w22
  __int64 v22; // x23
  char *v23; // x4
  __int64 v25; // x8
  __int64 v26; // x23
  unsigned int v33; // w11
  unsigned int v35; // w10
  unsigned int v36; // w20
  __int64 *v37; // x25
  unsigned int v38; // w21
  unsigned int v39; // w22
  char v40; // w24
  unsigned int v41; // w23
  __int64 v42; // x26
  __int64 v43; // x26
  double v44; // d0
  double v45; // d1
  double v46; // d2
  double v47; // d3
  double v48; // d4
  double v49; // d5
  double v50; // d6
  double v51; // d7
  __int64 v52; // x8

  if ( !result || !a2 )
  {
    v13 = "%s: Parameter(s) null";
    return qdf_trace_msg(0x33u, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "hdd_put_sta_info_ref");
  }
  v12 = *a2;
  if ( !*a2 )
  {
    v13 = "%s: station info NULL";
    return qdf_trace_msg(0x33u, 2u, v13, a5, a6, a7, a8, a9, a10, a11, a12, "hdd_put_sta_info_ref");
  }
  if ( a4 >= 0x23 )
    return qdf_trace_msg(
             0x33u,
             2u,
             "%s: Invalid sta_info debug id %d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             "hdd_put_sta_info_ref",
             a4);
  if ( (a3 & 1) != 0 )
  {
    v14 = a4;
    v15 = a2;
    v16 = a3;
    if ( (_ReadStatusReg(DAIF) & 0x80) != 0
      || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
      || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
    {
      v18 = result;
      raw_spin_lock(result + 24);
      result = v18;
    }
    else
    {
      v26 = result;
      raw_spin_lock_bh(result + 24);
      result = v26;
      *(_QWORD *)(v26 + 32) |= 1uLL;
    }
    a3 = v16;
    a2 = v15;
    a4 = v14;
  }
  v19 = v12 + 4LL * a4;
  if ( !*(_DWORD *)(v19 + 284) )
  {
    v20 = a2;
    v21 = a3;
    v22 = result;
    if ( a4 == 34 )
    {
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Debug string not found for debug id %d",
        a5,
        a6,
        a7,
        a8,
        a9,
        a10,
        a11,
        a12,
        "sta_info_string_from_dbgid",
        34);
      v23 = (char *)&unk_98C763;
    }
    else
    {
      v23 = sta_info_string_from_dbgid_strings[a4];
    }
    qdf_trace_msg(
      0x33u,
      2u,
      "%s: Sta_info ref count put is detected without get for debug id %s",
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      "hdd_put_sta_info_ref",
      v23);
    result = v22;
    a3 = v21;
    a2 = v20;
  }
  _X8 = (unsigned int *)(v19 + 284);
  _X9 = (unsigned int *)(v12 + 280);
  __asm { PRFM            #0x11, [X9] }
  do
    v33 = __ldxr(_X9);
  while ( __stxr(v33 - 1, _X9) );
  __asm { PRFM            #0x11, [X8] }
  do
    v35 = __ldxr(_X8);
  while ( __stxr(v35 - 1, _X8) );
  if ( *(_DWORD *)(v12 + 280) )
  {
    if ( (a3 & 1) != 0 )
    {
      v25 = *(_QWORD *)(result + 32);
      if ( (v25 & 1) != 0 )
      {
        *(_QWORD *)(result + 32) = v25 & 0xFFFFFFFFFFFFFFFELL;
        return raw_spin_unlock_bh(result + 24);
      }
      else
      {
        return raw_spin_unlock(result + 24);
      }
    }
  }
  else
  {
    v36 = *(unsigned __int8 *)(v12 + 32);
    v37 = a2;
    v38 = *(unsigned __int8 *)(v12 + 33);
    v39 = *(unsigned __int8 *)(v12 + 34);
    v40 = a3;
    v41 = *(unsigned __int8 *)(v12 + 37);
    if ( *(_DWORD *)(v12 + 264) )
    {
      v42 = result;
      _qdf_mem_free(*(_QWORD *)(v12 + 272));
      result = v42;
      *(_QWORD *)(v12 + 272) = 0;
      *(_DWORD *)(v12 + 264) = 0;
    }
    v43 = result;
    qdf_list_remove_node(result, (_QWORD *)v12);
    _qdf_mem_free(v12);
    *v37 = 0;
    if ( (v40 & 1) != 0 )
    {
      v52 = *(_QWORD *)(v43 + 32);
      if ( (v52 & 1) != 0 )
      {
        *(_QWORD *)(v43 + 32) = v52 & 0xFFFFFFFFFFFFFFFELL;
        raw_spin_unlock_bh(v43 + 24);
      }
      else
      {
        raw_spin_unlock(v43 + 24);
      }
    }
    return qdf_trace_msg(
             0x33u,
             8u,
             "STA_INFO: %02x:%02x:%02x:**:**:%02x freed",
             v44,
             v45,
             v46,
             v47,
             v48,
             v49,
             v50,
             v51,
             v36,
             v38,
             v39,
             v41);
  }
  return result;
}
