__int64 __fastcall sde_hw_lm_setup_out(__int64 a1, __int64 a2)
{
  int v4; // w21
  unsigned int v5; // w2

  v4 = sde_reg_read(a1, 0);
  sde_reg_write(a1, 4, (unsigned int)(*(_DWORD *)a2 | (*(_DWORD *)(a2 + 4) << 16)), "LM_OUT_SIZE");
  if ( *(_BYTE *)(a2 + 8) )
    v5 = 0x80000000;
  else
    v5 = 0;
  return sde_reg_write(a1, 0, v5 & 0x80000000 | v4 & 0x7FFFFFFF, "LM_OP_MODE");
}
