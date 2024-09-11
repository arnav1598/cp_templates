ll modmul(ll a, ll b, ll modulus)
{
    ll result = 0;
    a = a % modulus;
    while (b > 0)
    {
        if (b & 1)
            result = (result + a) % modulus;
        a = (a * 2) % modulus;
        b >>= 1;
    }
    return result % modulus;
}

// (a/b)%mod = a*modpow(b,mod-2,mod)