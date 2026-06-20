__int64 __fastcall gh_dbl_rx_callback_thread(__int64 a1, __int64 a2)
{
  void (__fastcall *v2)(__int64, __int64); // x8
  __int64 v3; // x1

  v2 = *(void (__fastcall **)(__int64, __int64))(a2 + 56);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a2 + 64);
    if ( *((_DWORD *)v2 - 1) != 127008684 )
      __break(0x8228u);
    v2(a1, v3);
  }
  return 1;
}
