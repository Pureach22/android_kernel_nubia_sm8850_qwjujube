__int64 __fastcall sg_new_write(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4, int a5, char a6, __int64 *a7)
{
  __int64 result; // x0
  __int64 v8; // x24
  __int64 v16; // x0
  __int64 v17; // x19
  int v18; // w8
  unsigned __int64 v19; // x0
  __int64 v20; // x23
  unsigned int v21; // w22
  size_t v22; // x24
  _QWORD v23[31]; // [xsp+8h] [xbp-108h] BYREF
  int v24; // [xsp+100h] [xbp-10h]
  __int64 v25; // [xsp+108h] [xbp-8h]

  v25 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a4 >= 0x58 )
  {
    v8 = a1 + 4096;
    v24 = 0;
    memset(v23, 0, sizeof(v23));
    *(_BYTE *)(a1 + 4905) = 1;
    v16 = sg_add_request(a1);
    if ( v16 )
    {
      v17 = v16;
      *(_BYTE *)(v16 + 242) = a6;
      if ( (unsigned int)get_sg_io_hdr(v16 + 56, a3) )
        goto LABEL_5;
      if ( *(_DWORD *)(v17 + 56) != 83 )
      {
        sg_remove_request(a1, (_QWORD *)v17);
        result = -38;
        goto LABEL_17;
      }
      v18 = *(_DWORD *)(v17 + 100);
      if ( (v18 & 4) != 0 )
      {
        if ( *(_DWORD *)(v17 + 68) > *(_DWORD *)(a1 + 120) )
        {
          sg_remove_request(a1, (_QWORD *)v17);
          result = -12;
          goto LABEL_17;
        }
        if ( (v18 & 1) != 0 )
        {
          sg_remove_request(a1, (_QWORD *)v17);
          result = -22;
          goto LABEL_17;
        }
        if ( *(_BYTE *)(v8 + 813) )
        {
          sg_remove_request(a1, (_QWORD *)v17);
          result = -16;
          goto LABEL_17;
        }
      }
      v19 = _msecs_to_jiffies(*(unsigned int *)(v17 + 96));
      v20 = *(_QWORD *)(v17 + 80);
      if ( v19 >= 0x7FFFFFFF )
        v21 = 0x7FFFFFFF;
      else
        v21 = v19;
      if ( !v20 || (v22 = *(unsigned __int8 *)(v17 + 64), (unsigned int)v22 < 6) || (unsigned int)(v22 - 253) <= 2 )
      {
        sg_remove_request(a1, (_QWORD *)v17);
        result = -90;
        goto LABEL_17;
      }
      _check_object_size(v23, *(unsigned __int8 *)(v17 + 64), 0);
      if ( inline_copy_from_user((int)v23, v20, v22) )
      {
LABEL_5:
        sg_remove_request(a1, (_QWORD *)v17);
        result = -14;
      }
      else if ( a5 && (unsigned int)sg_allow_access(a2, v23) )
      {
        sg_remove_request(a1, (_QWORD *)v17);
        result = -1;
      }
      else
      {
        LODWORD(result) = sg_common_write(a1, v17, v23, v21);
        if ( (result & 0x80000000) != 0 )
        {
          result = (int)result;
        }
        else
        {
          if ( a7 )
            *a7 = v17;
          result = a4;
        }
      }
    }
    else
    {
      result = -33;
    }
  }
  else
  {
    result = -22;
  }
LABEL_17:
  _ReadStatusReg(SP_EL0);
  return result;
}
