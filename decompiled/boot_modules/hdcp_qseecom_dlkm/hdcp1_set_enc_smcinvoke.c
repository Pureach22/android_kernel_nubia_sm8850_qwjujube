__int64 __fastcall hdcp1_set_enc_smcinvoke(__int64 a1, char a2)
{
  __int64 (*v2)(void); // x8
  __int64 result; // x0
  void *v4; // x0
  unsigned int v5; // w19
  int v6; // [xsp+4h] [xbp-1Ch] BYREF
  int *v7; // [xsp+8h] [xbp-18h]
  __int64 v8; // [xsp+10h] [xbp-10h]
  __int64 v9; // [xsp+18h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a1 || !*(_QWORD *)(a1 + 8) )
  {
    v4 = &unk_C470;
LABEL_12:
    printk(v4);
    result = 4294967274LL;
    goto LABEL_9;
  }
  if ( (*(_BYTE *)(a1 + 64) & 1) == 0 )
  {
    v4 = &unk_C905;
    goto LABEL_12;
  }
  if ( (*(_BYTE *)(a1 + 72) & 1) != 0 )
  {
    v2 = *(__int64 (**)(void))a1;
    v6 = a2 & 1;
    v7 = &v6;
    v8 = 4;
    if ( *((_DWORD *)v2 - 1) != 816020464 )
      __break(0x8228u);
    result = v2();
    if ( (_DWORD)result )
    {
      v5 = result;
      printk(&unk_BDFB);
      result = v5;
    }
  }
  else
  {
    printk(&unk_C830);
    result = 4294967274LL;
  }
LABEL_9:
  _ReadStatusReg(SP_EL0);
  return result;
}
