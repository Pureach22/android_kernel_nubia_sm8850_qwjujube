__int64 __fastcall dp_ctrl_isr(__int64 result)
{
  __int64 v1; // x19
  void (*v2)(void); // x8
  _DWORD *v3; // x8
  int v4; // w8

  if ( result )
  {
    v1 = result;
    v2 = *(void (**)(void))(*(_QWORD *)(result + 176) + 160LL);
    if ( *((_DWORD *)v2 - 1) != -91942776 )
      __break(0x8228u);
    v2();
    result = sde_evtlog_log(
               sde_dbg_base_evtlog,
               "dp_ctrl_isr",
               1422,
               8,
               **(_DWORD **)(v1 + 176),
               *(_DWORD *)(*(_QWORD *)(v1 + 176) + 4LL),
               *(_DWORD *)(*(_QWORD *)(v1 + 176) + 8LL),
               *(_DWORD *)(*(_QWORD *)(v1 + 176) + 12LL),
               239);
    v3 = *(_DWORD **)(v1 + 176);
    if ( (*v3 & 1) != 0 )
    {
      result = complete(v1 + 224);
      v3 = *(_DWORD **)(v1 + 176);
      if ( (*v3 & 8) == 0 )
      {
LABEL_6:
        v4 = v3[2];
        if ( (v4 & 1) == 0 )
          goto LABEL_7;
        goto LABEL_12;
      }
    }
    else if ( (*v3 & 8) == 0 )
    {
      goto LABEL_6;
    }
    result = complete(v1 + 192);
    v4 = *(_DWORD *)(*(_QWORD *)(v1 + 176) + 8LL);
    if ( (v4 & 1) == 0 )
    {
LABEL_7:
      if ( (v4 & 8) == 0 )
        return result;
      return complete(v1 + 192);
    }
LABEL_12:
    result = complete(v1 + 192);
    if ( (*(_DWORD *)(*(_QWORD *)(v1 + 176) + 8LL) & 8) == 0 )
      return result;
    return complete(v1 + 192);
  }
  return result;
}
