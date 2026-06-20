unsigned __int64 load_builtin_regdb_keys()
{
  unsigned __int64 result; // x0

  result = keyring_alloc(".builtin_regdb_keys", 0, 0, *(_QWORD *)(_ReadStatusReg(SP_EL0) + 2304), 520814592, 2, 0, 0);
  builtin_regdb_keys = result;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_B70F2);
    x509_load_certificate_list(shipped_regdb_certs, (unsigned int)shipped_regdb_certs_len, builtin_regdb_keys);
    return 0;
  }
  return result;
}
