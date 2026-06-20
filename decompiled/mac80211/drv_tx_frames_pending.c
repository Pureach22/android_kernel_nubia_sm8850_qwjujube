__int64 __fastcall drv_tx_frames_pending(__int64 a1)
{
  __int64 (*v1)(void); // x8
  char v2; // w0

  v1 = *(__int64 (**)(void))(*(_QWORD *)(a1 + 464) + 504LL);
  if ( v1 )
  {
    if ( *((_DWORD *)v1 - 1) != 437960165 )
      __break(0x8228u);
    v2 = v1();
  }
  else
  {
    v2 = 0;
  }
  return v2 & 1;
}
