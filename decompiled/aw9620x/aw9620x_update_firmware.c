__int64 __fastcall aw9620x_update_firmware(__int64 a1, unsigned int *a2)
{
  __int64 v3; // x21
  int v5; // w4
  unsigned __int8 v6; // w1

  v3 = a2[21];
  dev_printk(&unk_142BB, *(_QWORD *)(a1 + 48), "[%s:%d] enter\n", "aw9620x_update_firmware", 3238);
  v5 = a2[25];
  v6 = *(_BYTE *)(a1 + 7);
  *(_DWORD *)(a1 + 644) = v5;
  return aw9620x_fw_update(a1, v6, (__int64)a2 + v3 + 8424, a2[20], v5);
}
