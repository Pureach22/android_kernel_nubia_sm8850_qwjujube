__int64 __fastcall sde_connector_atomic_check(__int64 a1, __int64 a2)
{
  __int64 (__fastcall *v2)(__int64, __int64, __int64); // x8
  __int64 v4; // x1

  if ( a1 )
  {
    v2 = *(__int64 (__fastcall **)(__int64, __int64, __int64))(a1 + 3104);
    if ( v2 )
    {
      v4 = *(_QWORD *)(a1 + 2760);
      if ( *((_DWORD *)v2 - 1) != -1659747915 )
        __break(0x8228u);
      return v2(a1, v4, a2);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    printk(&unk_242658, "sde_connector_atomic_check");
    return 4294967274LL;
  }
}
