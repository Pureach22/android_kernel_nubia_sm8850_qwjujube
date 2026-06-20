__int64 __fastcall _set_registers_pakala(__int64 a1)
{
  __int64 v1; // x23
  __int64 v3; // x22
  __int64 v4; // x24
  __int64 v5; // x25
  __int64 result; // x0
  unsigned __int64 StatusReg; // x8

  v1 = *(_QWORD *)(a1 + 2208);
  if ( v1 )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(cvp_driver + 48) + 264LL);
    if ( *(int *)(v1 + 224) >= 1 )
    {
      v4 = 0;
      v5 = 0;
      do
      {
        _write_register(a1, *(_DWORD *)(*(_QWORD *)(v1 + 216) + v4), *(_DWORD *)(*(_QWORD *)(v1 + 216) + v4 + 4));
        if ( (msm_cvp_debug & 0x200) != 0 && !msm_cvp_debug_out )
          printk(
            &unk_868C8,
            &unk_8425A,
            *(unsigned int *)(*(_QWORD *)(v1 + 216) + v4),
            *(unsigned int *)(*(_QWORD *)(v1 + 216) + v4 + 4));
        ++v5;
        v4 += 8;
      }
      while ( v5 < *(int *)(v1 + 224) );
    }
    _write_register(a1, 0x1C010u, 0xFFu);
    _write_register(a1, 0x1C018u, 7u);
    _write_register(a1, 0x1E018u, 1u);
    _write_register(a1, 0x1E028u, 1u);
    usleep_range_state(5, 10, 2);
    _write_register(a1, 0x1E018u, 0);
    _write_register(a1, 0xE0014u, 0);
    _write_register(a1, 0xA013Cu, **(_DWORD **)(v3 + 32));
    _write_register(a1, 0x13030u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 4LL));
    _write_register(a1, 0x13034u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 8LL));
    _write_register(a1, 0x13038u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 12LL));
    _write_register(a1, 0x13040u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 20LL));
    _write_register(a1, 0x13048u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 24LL));
    _write_register(a1, 0x13430u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 4LL));
    _write_register(a1, 0x13434u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 8LL));
    _write_register(a1, 0x13438u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 12LL));
    _write_register(a1, 0x13440u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 20LL));
    _write_register(a1, 0x13448u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 24LL));
    _write_register(a1, 0x13830u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 4LL));
    _write_register(a1, 0x13834u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 8LL));
    _write_register(a1, 0x13838u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 16LL));
    _write_register(a1, 0x13840u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 20LL));
    _write_register(a1, 0x13848u, *(_DWORD *)(*(_QWORD *)(v3 + 32) + 24LL));
    _write_register(a1, 0x13108u, 1u);
    _write_register(a1, 0x13188u, 1u);
    _write_register(a1, 0x13508u, 1u);
    _write_register(a1, 0x13588u, 1u);
    _write_register(a1, 0x1A008u, 3u);
    _write_register(a1, 0x17040u, 1u);
    return 0;
  }
  else
  {
    result = 4294967274LL;
    if ( (msm_cvp_debug & 1) != 0 && !msm_cvp_debug_out )
    {
      StatusReg = _ReadStatusReg(SP_EL0);
      printk(&unk_89A6B, *(unsigned int *)(StatusReg + 1800), *(unsigned int *)(StatusReg + 1804), &unk_8E7CE);
      return 4294967274LL;
    }
  }
  return result;
}
