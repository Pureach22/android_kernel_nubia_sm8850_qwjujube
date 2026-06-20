__int64 __fastcall dp_debug_sim_hpd_cb(__int64 a1, __int64 a2, char a3)
{
  __int64 (*v3)(void); // x10
  __int64 (*v5)(void); // x8

  if ( (a3 & 1) != 0 )
  {
    v3 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 104) + 56LL);
    if ( *((_DWORD *)v3 - 1) != -143022559 )
      __break(0x822Au);
    return v3();
  }
  else
  {
    v5 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 104) + 48LL);
    if ( *((_DWORD *)v5 - 1) != -517830654 )
      __break(0x8228u);
    return v5();
  }
}
