__int64 __fastcall sde_hw_ds_setup_opmode(__int64 a1, int a2)
{
  int v4; // w0
  unsigned int v5; // w2

  v4 = sde_reg_read(a1, 0);
  if ( a2 )
  {
    v5 = v4 | a2;
  }
  else if ( (v4 & 0x10000) != 0 )
  {
    v5 = 0;
  }
  else
  {
    v5 = v4 & ~(unsigned int)(1LL << ((unsigned __int8)*(_DWORD *)(a1 + 32) - 1));
  }
  return sde_reg_write(a1, 0, v5, "DEST_SCALER_OP_MODE");
}
