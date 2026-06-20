__int64 __fastcall sde_fence_dump(__int64 a1)
{
  __int64 v2; // x8
  void (*v3)(void); // x9
  void (__fastcall *v4)(_QWORD); // x8
  void (__fastcall *v5)(_QWORD); // x8
  void (__fastcall *v6)(_QWORD); // x8
  __int64 result; // x0
  void (__fastcall *v8)(__int64); // x8
  unsigned __int64 v9; // x20

  _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(void (**)(void))(v2 + 64);
  if ( v3 )
  {
    if ( *((_DWORD *)v3 - 1) != -938580849 )
      __break(0x8229u);
    v3();
    v2 = *(_QWORD *)(a1 + 8);
  }
  v4 = *(void (__fastcall **)(_QWORD))(v2 + 8);
  if ( *((_DWORD *)v4 - 1) != -352706110 )
    __break(0x8228u);
  v4(a1);
  v5 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 16LL);
  if ( *((_DWORD *)v5 - 1) != -352706110 )
    __break(0x8228u);
  v5(a1);
  v6 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 8) + 32LL);
  if ( v6 )
  {
    if ( *((_DWORD *)v6 - 1) != 1879296680 )
      __break(0x8228u);
    v6(a1);
  }
  dma_fence_get_status(a1);
  result = printk(&unk_25BE93, "sde_fence_dump");
  if ( *(_UNKNOWN **)(a1 + 8) == &dma_fence_array_ops )
  {
    v8 = (void (__fastcall *)(__int64))dma_fence_array_create;
    if ( *((_DWORD *)dma_fence_array_create - 1) != -352706110 )
      __break(0x8228u);
    v8(a1);
    result = printk(&unk_25BF0D, "sde_fence_dump");
    if ( *(_DWORD *)(a1 + 68) )
    {
      v9 = 0;
      do
        result = sde_fence_dump(*(_QWORD *)(*(_QWORD *)(a1 + 80) + 8 * v9++));
      while ( v9 < *(unsigned int *)(a1 + 68) );
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
