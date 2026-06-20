__int64 __fastcall sde_setup_pipe_pa_cont_v1_7(__int64 a1, int *a2)
{
  int v2; // w22
  unsigned int v4; // w20
  int v5; // w21
  int v6; // w8
  int v7; // w8
  unsigned int v8; // w2

  v2 = *a2;
  v4 = *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(a1 + 56) + 48LL) + 180LL);
  v5 = sde_reg_read(a1, v4);
  sde_reg_write(a1, v4 + 284, (unsigned __int8)v2, "base + offset");
  if ( (v5 & 0xE0000E0) != 0 )
    v6 = -268435457;
  else
    v6 = -268435473;
  v7 = v6 & v5;
  if ( v2 )
    v8 = v5 | 0x10000010;
  else
    v8 = v7;
  return sde_reg_write(a1, v4, v8, "base");
}
