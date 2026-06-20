_QWORD *__fastcall ieee80211_fragment_element(_QWORD *result, unsigned __int64 a2, char a3)
{
  _BYTE *v3; // x19
  _QWORD *v4; // x21
  unsigned __int64 v5; // x8
  __int64 v7; // x23
  __int64 v8; // x24

  if ( a2 )
  {
    v3 = (_BYTE *)a2;
    v4 = result;
    v5 = result[28] + *((unsigned int *)result + 28) + ~a2;
    if ( (unsigned int)v5 >= 0x100 )
    {
      v7 = 0;
      v8 = (unsigned int)(*((_DWORD *)result + 56) + *((_DWORD *)result + 28) + ~(_DWORD)a2);
      do
      {
        *v3 = -1;
        skb_put(v4, 2);
        v7 -= 255;
        result = memmove(v3 + 258, v3 + 256, v8 + v7);
        v3[256] = a3;
        v3 += 257;
      }
      while ( (unsigned __int64)(v8 + v7) > 0xFF );
      LOBYTE(v5) = v8 + v7;
    }
    *v3 = v5;
  }
  return result;
}
