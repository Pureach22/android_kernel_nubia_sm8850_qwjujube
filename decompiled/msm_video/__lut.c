void *__fastcall _lut(int a1, int a2, int a3)
{
  unsigned int v3; // w8

  v3 = a2 * a1;
  if ( a2 * a1 <= 921600 )
  {
    if ( a3 < 31 )
      return &LUT;
    if ( (unsigned int)a3 <= 0x3C )
      return &unk_9C300;
    return &unk_9C6C0;
  }
  if ( v3 <= 0x1FE000 )
  {
    if ( a3 < 31 )
      return &unk_9C360;
    if ( (unsigned int)a3 <= 0x3C )
      return &unk_9C3C0;
    return &unk_9C6C0;
  }
  if ( v3 <= 0x384000 )
  {
    if ( a3 < 31 )
      return &unk_9C420;
    if ( (unsigned int)a3 <= 0x3C )
      return &unk_9C480;
    return &unk_9C6C0;
  }
  if ( v3 <= 0x7E9000 )
  {
    if ( a3 < 31 )
      return &unk_9C4E0;
    if ( (unsigned int)a3 <= 0x3C )
      return &unk_9C540;
    return &unk_9C6C0;
  }
  if ( v3 <= 0x870000 )
  {
    if ( a3 < 31 )
      return &unk_9C5A0;
    if ( (unsigned int)a3 <= 0x3C )
      return &unk_9C600;
    return &unk_9C6C0;
  }
  if ( v3 > 0x900000 )
    return &unk_9C6C0;
  if ( a3 <= 30 )
    return &unk_9C660;
  else
    return &unk_9C6C0;
}
