__int64 __fastcall sde_connector_trigger_event(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        unsigned int a5,
        unsigned int a6,
        unsigned int a7)
{
  __int64 result; // x0
  __int64 v15; // x28
  __int64 v16; // x0
  __int64 v17; // x8
  _DWORD *v18; // x26
  __int64 v19; // x25

  result = 4294967274LL;
  if ( a1 && a2 <= 4 )
  {
    v15 = a1;
    v16 = raw_spin_lock_irqsave(a1 + 4352);
    v17 = v15 + 16LL * a2;
    v18 = *(_DWORD **)(v17 + 4272);
    v19 = *(_QWORD *)(v17 + 4280);
    raw_spin_unlock_irqrestore(v15 + 4352, v16);
    if ( v18 )
    {
      if ( *(v18 - 1) != 741643664 )
        __break(0x823Au);
      return ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64, _QWORD, _QWORD, _QWORD, _QWORD))v18)(
               a2,
               a3,
               v19,
               a4,
               a5,
               a6,
               a7);
    }
    else
    {
      return 4294967285LL;
    }
  }
  return result;
}
