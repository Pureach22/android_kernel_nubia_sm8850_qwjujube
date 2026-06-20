__int64 __fastcall qdf_is_drv_connected(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 (*v8)(void); // x8
  char v9; // w0

  v8 = (__int64 (*)(void))is_drv_connected_cb;
  if ( is_drv_connected_cb )
  {
    if ( *((_DWORD *)is_drv_connected_cb - 1) != 799902358 )
      __break(0x8228u);
    v9 = v8();
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: drv connected callback is not registered",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "qdf_is_drv_connected");
    v9 = 0;
  }
  return v9 & 1;
}
