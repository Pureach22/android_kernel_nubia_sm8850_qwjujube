unsigned __int64 __fastcall qcom_reboot_reason_probe(__int64 a1)
{
  __int64 v1; // x21
  _QWORD *v3; // x0
  _QWORD *v4; // x20
  unsigned __int64 result; // x0

  v1 = a1 + 16;
  v3 = (_QWORD *)devm_kmalloc(a1 + 16, 40, 3520);
  if ( !v3 )
    return 4294967284LL;
  v4 = v3;
  *v3 = v1;
  result = nvmem_cell_get(v1, "restart_reason");
  v4[4] = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    v4[1] = qcom_reboot_reason_reboot;
    *((_DWORD *)v4 + 6) = 255;
    register_reboot_notifier(v4 + 1);
    *(_QWORD *)(a1 + 168) = v4;
    return 0;
  }
  return result;
}
