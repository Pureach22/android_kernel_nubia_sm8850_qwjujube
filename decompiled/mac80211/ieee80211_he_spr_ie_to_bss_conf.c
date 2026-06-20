__int64 __fastcall ieee80211_he_spr_ie_to_bss_conf(__int64 result, char *a2)
{
  _BYTE *v2; // x8
  char v3; // w9
  __int64 v4; // x8

  *(_QWORD *)(result + 425) = 0;
  *(_QWORD *)(result + 412) = 0;
  *(_QWORD *)(result + 420) = 0;
  if ( a2 )
  {
    v2 = a2 + 1;
    v3 = *a2;
    *(_BYTE *)(result + 413) = *a2;
    if ( (v3 & 4) != 0 )
    {
      *(_BYTE *)(result + 414) = a2[1];
      v2 = a2 + 2;
      v3 = *a2;
    }
    if ( (v3 & 8) != 0 )
    {
      *(_BYTE *)(result + 415) = *v2;
      *(_BYTE *)(result + 416) = v2[1];
      *(_QWORD *)(result + 417) = *(_QWORD *)(v2 + 2);
      v4 = *(_QWORD *)(v2 + 10);
      *(_BYTE *)(result + 412) = 1;
      *(_QWORD *)(result + 425) = v4;
    }
  }
  return result;
}
