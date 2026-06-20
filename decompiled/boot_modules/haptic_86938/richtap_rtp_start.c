bool __fastcall richtap_rtp_start(__int64 a1)
{
  void (__fastcall *v2)(__int64, __int64); // x8
  void (__fastcall *v3)(__int64, __int64); // x8
  int v4; // w21
  __int64 (__fastcall *v5)(_QWORD); // x8
  int v6; // w20
  void (__fastcall *v8)(_QWORD); // x8

  mutex_lock(a1 + 752);
  v2 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 152LL);
  if ( *((_DWORD *)v2 - 1) != 487251822 )
    __break(0x8228u);
  v2(a1, 2);
  v3 = *(void (__fastcall **)(__int64, __int64))(*(_QWORD *)(a1 + 1480) + 96LL);
  if ( *((_DWORD *)v3 - 1) != 487251822 )
    __break(0x8228u);
  v3(a1, 1);
  usleep_range_state(2000, 2000, 2);
  v4 = -200;
  do
  {
    v5 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 352LL);
    if ( *((_DWORD *)v5 - 1) != 2018195540 )
      __break(0x8228u);
    v6 = v5(a1) & 0xF;
    if ( v6 == 8 )
    {
      printk(&unk_16665, "haptic_hv", 1277, "richtap_rtp_start");
      usleep_range_state(2000, 2500, 2);
      goto LABEL_15;
    }
    usleep_range_state(2000, 2500, 2);
  }
  while ( !__CFADD__(v4++, 1) );
  printk(&unk_152C3, "haptic_hv", 1289, "richtap_rtp_start");
  v8 = *(void (__fastcall **)(_QWORD))(*(_QWORD *)(a1 + 1480) + 56LL);
  if ( *((_DWORD *)v8 - 1) != -2072377296 )
    __break(0x8228u);
  v8(a1);
LABEL_15:
  mutex_unlock(a1 + 752);
  return v6 == 8;
}
