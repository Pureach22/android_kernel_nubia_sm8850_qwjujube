__int64 __fastcall qcom_sg_do_vmap(__int64 a1)
{
  unsigned __int64 v2; // x19
  __int64 v3; // x20
  __int64 v4; // x9
  __int64 v5; // x1
  __int64 v6; // x2
  __int64 v7; // x22
  __int64 v8; // x8
  unsigned __int64 v9; // x24
  bool v10; // cf
  __int64 v11; // x25
  char v12; // w0
  __int64 v13; // x19
  __int64 result; // x0
  _QWORD *v15; // [xsp+0h] [xbp-20h] BYREF
  __int64 v16; // [xsp+8h] [xbp-18h]
  __int64 v17; // [xsp+10h] [xbp-10h]
  __int64 v18; // [xsp+18h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = (unsigned __int64)(*(_QWORD *)(a1 + 72) + 4095LL) >> 12;
  v3 = vmalloc_noprof(8LL * (int)v2);
  v16 = 0;
  v17 = 0;
  v15 = nullptr;
  if ( v3 )
  {
    v4 = 0x68000000000703LL;
    v5 = *(_QWORD *)(a1 + 80);
    v6 = *(unsigned int *)(a1 + 92);
    if ( arm64_use_ng_mappings )
      v4 = 0x68000000000F03LL;
    if ( *(_BYTE *)(a1 + 112) )
      v7 = v4 | 0x60000000000008LL;
    else
      v7 = v4;
    _sg_page_iter_start(&v15, v5, v6, 0);
    if ( (_sg_page_iter_next(&v15) & 1) != 0 )
    {
      v8 = 0;
      v9 = 8LL * (int)v2;
      while ( 1 )
      {
        if ( (int)v2 <= v8 >> 3 )
        {
          __break(0x800u);
          if ( v8 < 0 )
            break;
        }
        else if ( v8 < 0 )
        {
          break;
        }
        if ( 8LL * (int)v2 < (unsigned __int64)v8 )
          break;
        v10 = v9 >= 8;
        v9 -= 8LL;
        if ( !v10 )
          break;
        v11 = v8 + 8;
        *(_QWORD *)(v3 + v8) = (*v15 & 0xFFFFFFFFFFFFFFFCLL) + ((unsigned __int64)(unsigned int)v16 << 6);
        v12 = _sg_page_iter_next(&v15);
        v8 = v11;
        if ( (v12 & 1) == 0 )
          goto LABEL_18;
      }
      __break(1u);
    }
LABEL_18:
    v13 = vmap(v3, (unsigned int)v2, 4, v7);
    vfree(v3);
    if ( v13 )
      result = v13;
    else
      result = -12;
  }
  else
  {
    result = -12;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
