__int64 __fastcall validate_write_reg(unsigned int *a1)
{
  __int64 v1; // x8
  unsigned int v2; // w2
  unsigned int v3; // w3
  unsigned int v4; // w1
  __int64 v5; // x1

  v1 = *a1;
  if ( (unsigned int)v1 >= 7 )
  {
    __break(0x5512u);
    return validate_write_multi_lut_reg();
  }
  else
  {
    v2 = a1[11];
    v3 = v2 + ops_mem_size[v1];
    v4 = *(_DWORD *)(*((_QWORD *)a1 + 3) + 16LL) - *(_DWORD *)(*((_QWORD *)a1 + 3) + 20LL);
    if ( v4 >= v3 )
    {
      if ( *((_QWORD *)a1 + 4) )
      {
        if ( (v2 & 0xFFFF0003) != 0 )
        {
          _drm_err("Invalid data size %d max %zd align %x\n", v2, 0x3FFF, v2 & 3);
        }
        else
        {
          v5 = a1[5];
          if ( (v5 & 0xFFC00003) == 0 )
            return 0;
          _drm_err("invalid offset %d max %zd align %x\n", v5, 0x3FFFFF, v5 & 3);
        }
      }
      else
      {
        _drm_err("invalid data %pK size %d exp sz %d\n", nullptr, v2, v3);
      }
    }
    else
    {
      _drm_err("buffer is full sz %d needs %d bytes\n", v4, v3);
    }
    return 4294967274LL;
  }
}
