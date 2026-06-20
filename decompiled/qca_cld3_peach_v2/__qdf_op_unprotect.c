__int64 _qdf_op_unprotect()
{
  __int64 (*v0)(void); // x8
  __int64 result; // x0

  v0 = (__int64 (*)(void))_on_op_unprotect;
  if ( _on_op_unprotect )
  {
    if ( *((_DWORD *)_on_op_unprotect - 1) != -110690895 )
      __break(0x8228u);
    return v0();
  }
  return result;
}
