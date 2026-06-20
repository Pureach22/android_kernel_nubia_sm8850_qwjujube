__int64 _qdf_trigger_self_recovery()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))self_recovery_cb;
  if ( self_recovery_cb )
  {
    if ( *((_DWORD *)self_recovery_cb - 1) != 1341749752 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
