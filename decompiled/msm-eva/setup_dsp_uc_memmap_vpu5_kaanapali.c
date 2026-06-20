__int64 __fastcall setup_dsp_uc_memmap_vpu5_kaanapali(__int64 a1)
{
  _write_register(a1, 0xA0034u, *(_DWORD *)(a1 + 312));
  _write_register(a1, 0xA0038u, *(_DWORD *)(a1 + 312));
  return _write_register(a1, 0xA003Cu, *(_DWORD *)(a1 + 416));
}
