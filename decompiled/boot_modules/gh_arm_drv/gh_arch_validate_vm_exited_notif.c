__int64 __fastcall gh_arch_validate_vm_exited_notif(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // w8

  v4 = *(unsigned __int16 *)(a2 + 2);
  if ( v4 == 1 || v4 == 2 )
    goto LABEL_6;
  if ( v4 != 3 )
    return 4294967274LL;
  if ( a1 == 12 )
  {
    LOWORD(v4) = 2;
LABEL_6:
    *(_WORD *)(a2 + 2) = v4;
    return 0;
  }
  printk(&unk_642C, "gh_arch_validate_vm_exited_notif", a1, a4);
  return 4294967274LL;
}
