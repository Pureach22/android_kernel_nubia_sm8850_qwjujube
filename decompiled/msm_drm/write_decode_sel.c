__int64 __fastcall write_decode_sel(unsigned int *a1)
{
  char v2; // w8
  _DWORD *v3; // x23
  __int64 v4; // x25
  unsigned int v5; // w8
  unsigned __int64 v6; // x8
  unsigned __int64 v7; // x28
  __int64 v8; // x1
  __int64 v9; // x8

  v2 = 0;
  v3 = (_DWORD *)(*(_QWORD *)(*((_QWORD *)a1 + 3) + 32LL) + *(unsigned int *)(*((_QWORD *)a1 + 3) + 20LL));
  *v3 = reg_dma_decode_sel;
  v4 = a1[1];
  v3[1] = 0;
  do
  {
    v6 = (-1LL << v2) & v4;
    if ( !v6 )
      break;
    v7 = __clz(__rbit64(v6));
    v8 = 1LL << v7;
    if ( (int)(1LL << v7) < 0x8000 )
    {
      if ( (int)v8 > 511 )
      {
        if ( (int)v8 > 4095 )
        {
          switch ( (_DWORD)v8 )
          {
            case 0x1000:
              v5 = v3[1] | 0x20;
              break;
            case 0x2000:
              v5 = v3[1] | 0x40;
              break;
            case 0x4000:
              v5 = v3[1] | 0x80;
              break;
            default:
              goto LABEL_63;
          }
        }
        else
        {
          switch ( (_DWORD)v8 )
          {
            case 0x200:
              v5 = v3[1] | 0x40000;
              break;
            case 0x400:
              v5 = v3[1] | 0x80000;
              break;
            case 0x800:
              v5 = v3[1] | 0x100000;
              break;
            default:
              goto LABEL_63;
          }
        }
      }
      else if ( (int)v8 > 3 )
      {
        switch ( (_DWORD)v8 )
        {
          case 4:
            v5 = v3[1] | 4;
            break;
          case 8:
            v5 = v3[1] | 8;
            break;
          case 0x100:
            v5 = v3[1] | 0x20000;
            break;
          default:
            goto LABEL_63;
        }
      }
      else
      {
        switch ( (_DWORD)v8 )
        {
          case 0x80000000:
            v5 = v3[1] | 0x80000000;
            break;
          case 1:
            v5 = v3[1] | 1;
            break;
          case 2:
            v5 = v3[1] | 2;
            break;
          default:
            goto LABEL_63;
        }
      }
    }
    else if ( (int)v8 < 0x200000 )
    {
      if ( (int)v8 >= 0x40000 )
      {
        switch ( (_DWORD)v8 )
        {
          case 0x40000:
            v5 = v3[1] | 0x400000;
            break;
          case 0x80000:
            v5 = v3[1] | 0x800000;
            break;
          case 0x100000:
            v5 = v3[1] | 0x200;
            break;
          default:
            goto LABEL_63;
        }
      }
      else
      {
        switch ( (_DWORD)v8 )
        {
          case 0x8000:
            v5 = v3[1] | 0x100;
            break;
          case 0x10000:
            v5 = v3[1] | 0x10;
            break;
          case 0x20000:
            v5 = v3[1] | 0x200000;
            break;
          default:
            goto LABEL_63;
        }
      }
    }
    else if ( (int)v8 <= 0xFFFFFF )
    {
      switch ( (_DWORD)v8 )
      {
        case 0x200000:
          v5 = v3[1] | 0x400;
          break;
        case 0x400000:
          v5 = v3[1] | 0x1000000;
          break;
        case 0x800000:
          v5 = v3[1] | 0x2000000;
          break;
        default:
          goto LABEL_63;
      }
    }
    else if ( (int)v8 > 0x3FFFFFF )
    {
      if ( (_DWORD)v8 == 0x4000000 )
      {
        v5 = v3[1] | 0x8000;
      }
      else
      {
        if ( (_DWORD)v8 != 0x8000000 )
        {
LABEL_63:
          _drm_err("block not supported %zx\n", v8);
          goto LABEL_4;
        }
        v5 = v3[1] | 0x10000;
      }
    }
    else if ( (_DWORD)v8 == 0x1000000 )
    {
      v5 = v3[1] | 0x2000;
    }
    else
    {
      if ( (_DWORD)v8 != 0x2000000 )
        goto LABEL_63;
      v5 = v3[1] | 0x4000;
    }
    v3[1] = v5;
LABEL_4:
    v2 = v7 + 1;
  }
  while ( v7 < 0x1F );
  v9 = *a1;
  if ( (unsigned int)v9 >= 7 )
  {
    __break(0x5512u);
    return write_single_reg();
  }
  else
  {
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL) += ops_mem_size[v9];
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 44LL) |= 1u;
    *(_DWORD *)(*((_QWORD *)a1 + 3) + 40LL) = 126;
    return 0;
  }
}
