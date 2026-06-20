__int64 __fastcall sde_fence_list_dump(__int64 a1, __int64 *a2)
{
  __int64 v4; // x8
  void (*v5)(void); // x9
  __int64 (__fastcall *v6)(_QWORD); // x8
  __int64 v7; // x20
  const char *v8; // x21
  __int64 (__fastcall *v9)(_QWORD); // x8
  __int64 v10; // x0
  __int64 v11; // x22
  const char *v12; // x23
  __int64 (__fastcall *v13)(_QWORD); // x8
  __int64 v14; // x6
  __int64 result; // x0
  _QWORD v16[17]; // [xsp+8h] [xbp-88h] BYREF

  v16[16] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 8);
  v5 = *(void (**)(void))(v4 + 64);
  memset(v16, 0, 128);
  if ( v5 )
  {
    if ( *((_DWORD *)v5 - 1) != -938580849 )
      __break(0x8229u);
    v5();
    v4 = *(_QWORD *)(a1 + 8);
  }
  v6 = *(__int64 (__fastcall **)(_QWORD))(v4 + 8);
  v7 = *a2;
  if ( *((_DWORD *)v6 - 1) != -352706110 )
    __break(0x8228u);
  v8 = (const char *)v6(a1);
  v9 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 16LL);
  if ( *((_DWORD *)v9 - 1) != -352706110 )
    __break(0x8228u);
  v10 = v9(a1);
  v11 = *(_QWORD *)(a1 + 40);
  v12 = (const char *)v10;
  v13 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 32LL);
  if ( v13 )
  {
    if ( *((_DWORD *)v13 - 1) != 1879296680 )
      __break(0x8228u);
    v14 = v13(a1) & 1;
  }
  else
  {
    LODWORD(v14) = -1;
  }
  result = seq_printf(
             v7,
             "fence name:%s timeline name:%s seqno:0x%llx timeline:%s signaled:0x%x\n",
             v8,
             v12,
             v11,
             (const char *)v16,
             v14);
  _ReadStatusReg(SP_EL0);
  return result;
}
