__int64 __fastcall dp_tx_comp_process_desc(
        __int64 result,
        __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 (*v14)(void); // x8
  __int64 v15; // x19
  __int64 v16; // x19
  const char *v17; // x2
  __int64 v18; // x19
  __int64 v19; // x20
  __int64 v20; // x21

  if ( *(_BYTE *)(*(_QWORD *)(a2 + 56) + 95937LL) == 1 )
  {
    v18 = result;
    v19 = a2;
    v20 = a12;
    ktime_get_with_offset(0);
    a12 = v20;
    result = v18;
    a2 = v19;
  }
  if ( *(_QWORD *)(a2 + 72) || (*(_BYTE *)(a2 + 34) & 4) != 0 )
    goto LABEL_17;
  if ( !a12 )
  {
    v12 = *(_QWORD *)(result + 20112);
    if ( v12 )
      goto LABEL_7;
LABEL_15:
    v16 = a2;
    v17 = "%s: monitor soc is NULL";
    goto LABEL_16;
  }
  v12 = *(_QWORD *)(result + 20112);
  if ( !v12 )
    goto LABEL_15;
LABEL_7:
  v13 = *(_QWORD *)(v12 + 416);
  if ( !v13 || (v14 = *(__int64 (**)(void))(v13 + 344)) == nullptr )
  {
    v16 = a2;
    v17 = "%s: callback not registered";
LABEL_16:
    result = qdf_trace_msg(0x92u, 8u, v17, a3, a4, a5, a6, a7, a8, a9, a10, "dp_monitor_tx_add_to_comp_queue");
    a2 = v16;
LABEL_17:
    *(_DWORD *)(a2 + 32) |= 0x40u;
    return result;
  }
  v15 = a2;
  if ( *((_DWORD *)v14 - 1) != 959629843 )
    __break(0x8228u);
  result = v14();
  a2 = v15;
  if ( (_DWORD)result )
    goto LABEL_17;
  return result;
}
