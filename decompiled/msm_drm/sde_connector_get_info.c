__int64 __fastcall sde_connector_get_info(__int64 a1, __int64 a2)
{
  __int64 (*v2)(void); // x8

  if ( a1 && a2 )
  {
    if ( *(_QWORD *)(a1 + 2760) && (v2 = *(__int64 (**)(void))(a1 + 2944)) != nullptr )
    {
      if ( *((_DWORD *)v2 - 1) != 81886827 )
        __break(0x8228u);
      return v2();
    }
    else
    {
      printk(&unk_27DE90, "sde_connector_get_info");
      return 4294967274LL;
    }
  }
  else
  {
    printk(&unk_23C279, "sde_connector_get_info");
    return 4294967274LL;
  }
}
