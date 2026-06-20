__int64 __fastcall adreno_queue_cmds(__int64 a1)
{
  __int64 v1; // x8
  __int64 (*v2)(void); // x8

  v1 = *(_QWORD *)(*(_QWORD *)a1 + 20896LL);
  if ( v1 && (v2 = *(__int64 (**)(void))(v1 + 8)) != nullptr )
  {
    if ( *((_DWORD *)v2 - 1) != -646102743 )
      __break(0x8228u);
    return v2();
  }
  else
  {
    __break(0x800u);
    return 4294967277LL;
  }
}
