__int64 __fastcall syna_cdev_devnode(__int64 *a1, _WORD *a2)
{
  __int64 v2; // x2

  if ( !a2 )
    return 0;
  *a2 = 1536;
  v2 = a1[14];
  if ( !v2 )
    v2 = *a1;
  return kasprintf(3264, unk_364AC, v2);
}
