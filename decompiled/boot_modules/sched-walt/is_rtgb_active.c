__int64 is_rtgb_active()
{
  char v0; // w8

  v0 = qword_67BA0;
  if ( qword_67BA0 )
    v0 = *(_BYTE *)(qword_67BA0 + 40);
  return v0 & 1;
}
