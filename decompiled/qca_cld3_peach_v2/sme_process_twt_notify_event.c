__int64 __fastcall sme_process_twt_notify_event(__int64 a1, unsigned int *a2)
{
  __int64 result; // x0
  __int64 (__fastcall *v5)(__int64, unsigned int *); // x8
  __int64 v6; // x0

  result = mlme_twt_set_wait_for_notify(*(_QWORD *)(a1 + 21624), *a2, 0);
  v5 = *(__int64 (__fastcall **)(__int64, unsigned int *))(a1 + 14544);
  if ( v5 )
  {
    v6 = *(_QWORD *)(a1 + 21624);
    if ( *((_DWORD *)v5 - 1) != 1390633307 )
      __break(0x8228u);
    return v5(v6, a2);
  }
  return result;
}
