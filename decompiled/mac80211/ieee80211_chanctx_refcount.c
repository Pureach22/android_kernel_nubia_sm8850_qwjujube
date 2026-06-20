__int64 __fastcall ieee80211_chanctx_refcount(__int64 a1, __int64 a2)
{
  __int64 result; // x0
  _QWORD *v3; // x9
  _QWORD *v4; // x9

  LODWORD(result) = -2;
  v3 = (_QWORD *)(a2 + 32);
  do
  {
    v3 = (_QWORD *)*v3;
    LODWORD(result) = result + 1;
  }
  while ( v3 != (_QWORD *)(a2 + 32) );
  v4 = (_QWORD *)(a2 + 48);
  do
  {
    v4 = (_QWORD *)*v4;
    result = (unsigned int)(result + 1);
  }
  while ( v4 != (_QWORD *)(a2 + 48) );
  return result;
}
