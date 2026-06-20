__int64 __fastcall sde_encoder_get_programmed_fetch_time(__int64 a1)
{
  __int64 v1; // x8

  if ( a1 && (v1 = *(_QWORD *)(a1 + 200)) != 0 )
  {
    if ( *(_DWORD *)(a1 + 648) == 1 )
      return *(unsigned int *)(v1 + 2304);
    else
      return 0;
  }
  else
  {
    printk(&unk_223EAA, "sde_encoder_get_programmed_fetch_time");
    return 0xFFFFFFFFLL;
  }
}
