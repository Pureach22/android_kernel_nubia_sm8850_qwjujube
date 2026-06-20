__int64 __fastcall edid_mode_store(__int64 a1, int a2, char *s, __int64 a4)
{
  __int64 v4; // x20
  __int16 v6; // w9
  __int64 v8; // [xsp+0h] [xbp-10h] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v8 = 0;
  if ( !v4 )
  {
    printk(&unk_B00B, "edid_mode_store");
    goto LABEL_7;
  }
  if ( sscanf(s, "%d %d", (char *)&v8 + 4, &v8) != 2 || !HIDWORD(v8) || (v6 = v8, !(_DWORD)v8) )
  {
    *(_BYTE *)(v4 + 4018) = 0;
LABEL_7:
    a4 = -22;
    goto LABEL_8;
  }
  *(_WORD *)(v4 + 3324) = WORD2(v8);
  *(_BYTE *)(v4 + 4018) = 1;
  *(_WORD *)(v4 + 3334) = v6;
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return a4;
}
