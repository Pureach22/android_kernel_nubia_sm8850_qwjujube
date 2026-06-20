__int64 __fastcall dynamic_size_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v5; // x9
  int v6; // w0
  int v8; // w20

  v5 = memsh_child;
  if ( *(_QWORD *)(memsh_child + 64) != a1 )
  {
    v5 = qword_8900;
    if ( *(_QWORD *)(qword_8900 + 64) != a1 )
    {
      v5 = qword_8908;
      if ( *(_QWORD *)(qword_8908 + 64) != a1 )
      {
        v5 = qword_8910;
        if ( *(_QWORD *)(qword_8910 + 64) != a1 )
        {
          v5 = qword_8918;
          if ( *(_QWORD *)(qword_8918 + 64) != a1 )
          {
            v5 = qword_8920;
            if ( *(_QWORD *)(qword_8920 + 64) != a1 )
            {
              v5 = qword_8928;
              if ( *(_QWORD *)(qword_8928 + 64) != a1 )
              {
                v5 = qword_8930;
                if ( *(_QWORD *)(qword_8930 + 64) != a1 )
                {
                  v5 = qword_8938;
                  if ( *(_QWORD *)(qword_8938 + 64) != a1 )
                  {
                    v5 = qword_8940;
                    if ( *(_QWORD *)(qword_8940 + 64) != a1 )
                      goto LABEL_15;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  if ( v5 )
  {
    v6 = kstrtouint(a3, 0, v5 + 4);
    if ( v6 < 0 )
    {
      v8 = v6;
      dev_err(*(_QWORD *)memsh_drv, "memshare: Failure to store dynamic size (error: %d)\n", v6);
      return v8;
    }
  }
  else
  {
LABEL_15:
    dev_err(*(_QWORD *)memsh_drv, "memshare: Write request for invalid client\n");
    return -22;
  }
  return a4;
}
