__int64 __fastcall qcom_pil_info_store(const char *a1, unsigned __int64 a2, unsigned int a3)
{
  unsigned __int64 v6; // x0
  __int64 v7; // x22
  unsigned __int64 v8; // x8
  int v9; // w25
  size_t v10; // x0
  __int64 v11; // x2
  __int64 v13; // [xsp+0h] [xbp-70h] BYREF
  __int64 v14; // [xsp+8h] [xbp-68h]
  __int64 v15; // [xsp+10h] [xbp-60h]
  __int64 v16; // [xsp+18h] [xbp-58h]
  __int64 v17; // [xsp+20h] [xbp-50h]
  __int64 v18; // [xsp+28h] [xbp-48h]
  __int64 v19; // [xsp+30h] [xbp-40h]
  __int64 v20; // [xsp+38h] [xbp-38h]
  __int64 v21; // [xsp+40h] [xbp-30h]
  __int64 v22; // [xsp+48h] [xbp-28h]
  __int64 v23; // [xsp+50h] [xbp-20h]
  __int64 v24; // [xsp+58h] [xbp-18h]
  char s1[8]; // [xsp+60h] [xbp-10h] BYREF
  __int64 v26; // [xsp+68h] [xbp-8h]

  v26 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  *(_QWORD *)s1 = 0;
  mutex_lock(&pil_reloc_lock);
  if ( !reloc_0 )
  {
    v23 = 0;
    v24 = 0;
    v21 = 0;
    v22 = 0;
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = 0;
    v15 = 0;
    v16 = 0;
    v13 = 0;
    v14 = 0;
    v6 = qcom_map_pil_imem_resource((__int64)"qcom,pil-reloc-info", (__int64)&v13);
    v7 = v6;
    if ( v6 <= 0xFFFFFFFFFFFFF000LL )
    {
      _memset_io(v6, 0, v14 - v13 + 1);
      reloc_0 = v7;
      reloc_1 = (unsigned int)(v14 - v13 + 1) / 0x14uLL;
    }
    else if ( (v6 & 0x80000000) != 0 )
    {
      goto LABEL_17;
    }
  }
  if ( reloc_1 )
  {
    v8 = 0;
    v9 = 1;
    while ( 1 )
    {
      v7 = reloc_0 + 20 * v8;
      _memcpy_fromio(s1, v7, 8);
      if ( !s1[0] )
        break;
      if ( !strncmp(s1, a1, 8u) )
        goto LABEL_16;
      v8 = v9++;
      if ( reloc_1 <= v8 )
        goto LABEL_11;
    }
    v10 = strlen(a1);
    if ( v10 >= 0x13 )
      v11 = 19;
    else
      v11 = v10;
    _memcpy_toio(v7, a1, v11);
LABEL_16:
    writel((unsigned int)a2, v7 + 8);
    writel(HIDWORD(a2), v7 + 12);
    writel(a3, v7 + 16);
    LODWORD(v7) = 0;
  }
  else
  {
LABEL_11:
    printk(&unk_6560);
    LODWORD(v7) = -12;
  }
LABEL_17:
  mutex_unlock(&pil_reloc_lock);
  _ReadStatusReg(SP_EL0);
  return (unsigned int)v7;
}
