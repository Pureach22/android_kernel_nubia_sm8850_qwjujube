__int64 __fastcall set_param_hfi_queue(__int64 a1, unsigned int a2, __int64 a3, unsigned int a4)
{
  __int64 v4; // x30
  __int64 (__fastcall *v9)(); // x8
  unsigned int v10; // w20

  if ( a1 && a2 < 6 )
  {
    mutex_lock(a1 + 1016);
    v9 = set_param_func[a2];
    if ( *((_DWORD *)v9 - 1) != 841852058 )
      __break(0x8228u);
    v10 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v9)(a1, a3, a4);
    mutex_unlock(a1 + 1016);
  }
  else
  {
    printk(&unk_1F095, "set_param_hfi_queue", 255, v4, a1);
    return (unsigned int)-22;
  }
  return v10;
}
