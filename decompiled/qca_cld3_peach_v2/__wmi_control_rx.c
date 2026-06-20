__int64 __fastcall _wmi_control_rx(
        __int64 *a1,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  _DWORD *v12; // x8
  unsigned int v13; // w20
  double v14; // d0
  double v15; // d1
  double v16; // d2
  double v17; // d3
  double v18; // d4
  double v19; // d5
  double v20; // d6
  double v21; // d7
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  int v30; // w8
  int v31; // w8
  __int64 v32; // x8
  __int64 result; // x0
  double v34; // d0
  double v35; // d1
  double v36; // d2
  double v37; // d3
  double v38; // d4
  double v39; // d5
  double v40; // d6
  double v41; // d7
  _QWORD *v42; // x22
  int v43; // w23
  int v44; // w24
  unsigned int v45; // w8
  __int64 v46; // x25
  unsigned int v47; // w9
  int *v48; // x8
  __int64 v49; // x9
  int v50; // t1
  __int64 v51; // x0
  __int64 v52; // x1
  _DWORD *v53; // x8
  unsigned __int64 StatusReg; // x8
  __int64 (__fastcall *v55)(_QWORD); // x8
  __int64 (__fastcall *v56)(_QWORD); // x8
  unsigned int *v57; // x9
  unsigned int v58; // w10
  __int64 v59; // x8
  __int64 v60; // x8
  __int64 v61; // x0
  __int64 v62; // x2
  _QWORD *v63; // x1
  _DWORD *v64; // x8
  _DWORD *v65; // x8
  int v66; // w8
  __int64 v67; // x9
  _QWORD *v68; // [xsp+0h] [xbp-20h] BYREF
  __int64 v69; // [xsp+8h] [xbp-18h]
  _QWORD v70[2]; // [xsp+10h] [xbp-10h] BYREF

  v70[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = *(_DWORD **)(a2 + 224);
  v69 = 0;
  v70[0] = 0;
  v68 = nullptr;
  v13 = *v12 & 0xFFFFFF;
  if ( v13 == 45065 )
  {
    qdf_trace_msg(0x31u, 8u, "%s: EVENT: 0x%x", a3, a4, a5, a6, a7, a8, a9, a10, "wmi_dump_event", 45065, v68, v69);
    __isb(0xFu);
    _ReadStatusReg(CNTVCT_EL0);
    qdf_trace_msg(0x31u, 8u, "%s: Time: 0x%llx", v14, v15, v16, v17, v18, v19, v20, v21, "wmi_dump_event");
    if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
      v30 = *(unsigned __int16 *)(a2 + 66);
    else
      v30 = 0;
    qdf_trace_msg(
      0x31u,
      8u,
      "%s: Length:%d\n",
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      v28,
      v29,
      "wmi_dump_event",
      (unsigned int)(*(_DWORD *)(a2 + 112) + v30));
    if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
      v31 = *(unsigned __int16 *)(a2 + 66);
    else
      v31 = 0;
    ((void (__fastcall *)(__int64, __int64, _QWORD, _QWORD))qdf_trace_hex_dump)(
      49,
      8,
      *(_QWORD *)(a2 + 224),
      (unsigned int)(*(_DWORD *)(a2 + 112) + v31));
  }
  v32 = *(_QWORD *)(a2 + 40);
  if ( v32 )
    *(_QWORD *)(a2 + 40) = v32 + 4;
  result = skb_pull(a2, 4);
  if ( result )
  {
    v42 = *(_QWORD **)(a2 + 224);
    if ( (*(_BYTE *)(a2 + 68) & 4) != 0 )
      v43 = *(unsigned __int16 *)(a2 + 66);
    else
      v43 = 0;
    v44 = *(_DWORD *)(a2 + 112);
    if ( !*((_DWORD *)a1 + 181) )
    {
      v51 = *a1;
      v52 = *(_QWORD *)(a2 + 224);
      v53 = *(_DWORD **)(a1[91] + 3992);
      if ( *(v53 - 1) != 1074126569 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD, _QWORD *))v53)(
                 v51,
                 v52,
                 (unsigned int)(v44 + v43),
                 v13,
                 v70);
      if ( (_DWORD)result )
      {
        result = qdf_trace_msg(
                   0x31u,
                   2u,
                   "%s: Error: id=0x%x, wmitlv check status=%d",
                   v34,
                   v35,
                   v36,
                   v37,
                   v38,
                   v39,
                   v40,
                   v41,
                   "__wmi_control_rx",
                   v13,
                   (unsigned int)result);
        goto LABEL_51;
      }
    }
    v45 = *(_DWORD *)(a1[95] + 3112);
    if ( !v45 )
      goto LABEL_25;
    v46 = 0;
    v47 = v45 >= 0x100 ? 256 : *(_DWORD *)(a1[95] + 3112);
    v48 = (int *)a1[5];
    v49 = 8LL * v47;
    while ( 1 )
    {
      v50 = *v48++;
      if ( v50 == v13 )
      {
        if ( *(_QWORD *)(a1[6] + v46) )
          break;
      }
      v46 += 8;
      if ( v49 == v46 )
        goto LABEL_25;
    }
    if ( v46 == 0x7FFFFFFF8LL )
    {
LABEL_25:
      result = qdf_trace_msg(
                 0x31u,
                 2u,
                 "%s : event handler is not registered: event id 0x%x",
                 v34,
                 v35,
                 v36,
                 v37,
                 v38,
                 v39,
                 v40,
                 v41,
                 "__wmi_control_rx",
                 v13,
                 v68,
                 v69);
      goto LABEL_51;
    }
    if ( *((_BYTE *)a1 + 680) == 1 )
    {
      if ( (_ReadStatusReg(DAIF) & 0x80) != 0
        || (StatusReg = _ReadStatusReg(SP_EL0), (*(_DWORD *)(StatusReg + 16) & 0xF0000) != 0)
        || (*(_DWORD *)(StatusReg + 16) & 0xFF00) != 0 )
      {
        raw_spin_lock(a1 + 83);
      }
      else
      {
        raw_spin_lock_bh(a1 + 83);
        a1[84] |= 1uLL;
      }
      v55 = *(__int64 (__fastcall **)(_QWORD))(a1[91] + 3536);
      if ( *((_DWORD *)v55 - 1) != -1896783675 )
        __break(0x8228u);
      if ( (v55(v13) & 1) == 0 )
      {
        v56 = *(__int64 (__fastcall **)(_QWORD))(a1[91] + 3528);
        if ( *((_DWORD *)v56 - 1) != -1896783675 )
          __break(0x8228u);
        if ( (v56(v13) & 1) == 0 )
        {
          v57 = (unsigned int *)a1[61];
          v58 = *v57;
          v59 = *(unsigned int *)(a1[95] + 7852);
          if ( wmi_event_log_max_entry <= *v57 )
          {
            *v57 = 0;
            v58 = *(_DWORD *)a1[61];
          }
          *(_DWORD *)(a1[59] + 32LL * v58) = v13;
          qdf_mem_copy(
            (void *)(a1[59] + 32LL * *(unsigned int *)a1[61] + 4),
            (char *)v42 + v59,
            (unsigned int)wmi_record_max_length);
          __isb(0xFu);
          *(_QWORD *)(a1[59] + 32LL * (unsigned int)(*(_DWORD *)a1[61])++ + 24) = _ReadStatusReg(CNTVCT_EL0);
          ++*((_DWORD *)a1 + 120);
        }
      }
      v60 = a1[84];
      if ( (v60 & 1) != 0 )
      {
        a1[84] = v60 & 0xFFFFFFFFFFFFFFFELL;
        result = raw_spin_unlock_bh(a1 + 83);
        if ( *((_DWORD *)a1 + 181) )
          goto LABEL_47;
        goto LABEL_59;
      }
      result = raw_spin_unlock(a1 + 83);
    }
    if ( *((_DWORD *)a1 + 181) )
    {
LABEL_47:
      v61 = *a1;
      v62 = (unsigned int)(v44 + v43);
      v63 = v42;
      v64 = *(_DWORD **)(a1[6] + v46);
LABEL_48:
      if ( *(v64 - 1) != -313353962 )
        __break(0x8228u);
      result = ((__int64 (__fastcall *)(__int64, _QWORD *, __int64))v64)(v61, v63, v62);
      goto LABEL_51;
    }
LABEL_59:
    v66 = *(_DWORD *)(a1[7] + v46 + 4);
    if ( v66 == 1 )
    {
      v67 = a1[6];
      v63 = &v68;
      v61 = *a1;
      v62 = (unsigned int)(v44 + v43);
      v68 = v42;
      v69 = v70[0];
      v64 = *(_DWORD **)(v67 + v46);
    }
    else
    {
      if ( v66 )
        goto LABEL_51;
      v64 = *(_DWORD **)(a1[6] + v46);
      if ( !v64 )
        goto LABEL_51;
      v61 = *a1;
      v63 = (_QWORD *)v70[0];
      v62 = (unsigned int)(v44 + v43);
    }
    goto LABEL_48;
  }
LABEL_51:
  if ( !*((_DWORD *)a1 + 181) )
  {
    v65 = *(_DWORD **)(a1[91] + 3984);
    if ( *(v65 - 1) != -1349327220 )
      __break(0x8228u);
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD *))v65)(v13, v70);
  }
  if ( a2 )
    result = _qdf_nbuf_free(a2);
  _ReadStatusReg(SP_EL0);
  return result;
}
